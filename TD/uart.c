#include "uart.h"
#include "bits.h"
#include "reg.h"
#include "led.h"

int UART_SUM = 0; // Global variable used to store the checksum(see uart_checksum())

void uart_init()
{
    clearBit(27, &SIM_SOPT2);
    setBit(26, &SIM_SOPT2); // use MCGPLLCLK clock for UART0
    setBit(16, &SIM_SOPT2); // divide MGPLLCLK by 2
    setBit(10, &SIM_SCGC4); // clock enabled for UART0

    UARTO_C2 = 0;                          // UART0 deactivated

    set_and_clear8(&UARTO_C4, 0xe0, 0x1d); // set bits [4:0] to 0b11101 (0d29)

    clearBit8(5, &UARTO_BDH);              // one stop bit
    set_and_clear8(&UARTO_BDL, 0x00, 0x7); // set bits [7:0] to 0b111 (0d7)
    set_and_clear8(&UARTO_BDH, 0xf0, 0x0); // set bits [3:0] to 0

    clearBit8(1, &UARTO_C1);               // parity disabled
    clearBit8(4, &UARTO_C1);               // 8-bit mode

    setBit(9, &SIM_SCGC5);                 // activate PORTA clock

    set_and_clear(&PORTA_PCR1, 0xfffff8ff, 0x200); // alt2 = 010 (RX)
    set_and_clear(&PORTA_PCR2, 0xfffff8ff, 0x200); // alt2 = 010 (TX)

    setBit8(2, &UARTO_C2); // Receiver enabled
    setBit8(3, &UARTO_C2); // Transmitter enabled
}

void uart_putchar(char c)
{
    while(getBit8(UARTO_S1,7) == 0); // While transmitter is active

    UARTO_D = c;
}

unsigned char uart_getchar()
{
    while(getBit8(UARTO_S1,5) == 0); // While receive data buffer is empty

    return UARTO_D;
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

void uart_checksum()
{
    for(int i = 0 ; i<1000 ;i++) // We expect that the checksum.py program sent 1000 char
    {
        UART_SUM += (int)uart_getchar();
    }
}

void uart_echo()
{
    uart_putchar(uart_getchar());
}
