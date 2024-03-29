#include "uart.h"
#include "bits.h"
#include "reg.h"
#include "led.h"
#include "irq.h"

char frame[192];

void uart_init()
{
    clearBit(27, &SIM_SOPT2);
    setBit(26, &SIM_SOPT2); // use MCGPLLCLK clock for UART0
    setBit(16, &SIM_SOPT2); // divide MGPLLCLK by 2
    UART0_ENABLED();

    // Initialisation of all the UART registers
    UART0_C2 = 0;                          
    set_and_clear8(&UART0_S1, 0x00, 0b11000000);
    UART0_S2 = 0;
    UART0_C1 = 0;
    set_and_clear8(&UART0_C3, 0x00, 0b00001111);
    set_and_clear8(&UART0_C5, 0b01011100, 0x00);
    set_and_clear8(&UART0_C4, 0x00, 0b00011111); // 11111 = 31 (38400)
    UART0_MA1 = 0;
    UART0_MA2 = 0;
    UART0_BDH = 0;
    set_and_clear8(&UART0_BDL, 0x00, 0x14); // set bits [7:0] to 0b10100 (0d20)

    PORTA_ENABLED();
    set_and_clear(&PORTA_PCR1, 0xfffff8ff, 0x200); // alt2 = 010 (RX)
    set_and_clear(&PORTA_PCR2, 0xfffff8ff, 0x200); // alt2 = 010 (TX)

    set_and_clear8(&UART0_C2, 0x00, 0b00101100); // activate Receiver, transmitter, and RDRF interruption

    irq_enable(12);
    for(int i = 0; i < 192; i++)
        frame[i] = 0x00;
}

void uart_putchar(char c)
{
    while(getBit8(UART0_S1,7) == 0); // While transmitter is active

    UART0_D = c;
}

unsigned char uart_getchar()
{
    while(getBit8(UART0_S1,5) == 0); // While receive data buffer is empty

    return UART0_D;
}

void uart_puts(const char *s)
{
    for(int i = 0; s[i] != 0; i++)
    {
        uart_putchar(s[i]);
    }
    uart_putchar('\n');
}

void uart_gets(char *s, int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        s[i] = uart_getchar();
        if(s[i] == '\n')
        {
            s[i+1] = 0;
            return;
        }
    }
    s[i] = 0;
}

void UART0_IRQHandler()
{
    static int char_count = 0;
    char c = UART0_D;
    if (c == 0xff) // a trame always begins with 0xff
    {
        char_count = 0;
        set_and_clear8(&UART0_S1, 0xe0, 0x00); // release all the error flags
    }
    else if (~(getBit8(UART0_S1,1) | getBit8(UART0_S1,3))) // if there is not an OR or FE error 
    {
        frame[char_count] = c;
        char_count++;
        if (char_count == 192)
            char_count = 0;
    }
    set_and_clear8(&UART0_S1, 0b11101010, 0x00); // release the error flags except OR and FE
}
