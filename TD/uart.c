#include "uart.h"
#include "bits.h"
#include "reg.h"

void uart_init()
{
    setBit(26, &SIM_SOPT2); // use MCGPLLCLK/2 clock for UART0
    clearBit(27, &SIM_SOPT2);
    setBit(10, &SIM_SCGC4); // clock enabled for UART0

    set_and_clear8(&UARTO_C2, 0xf3, 0x0c); // UART0 deactivated

    set_and_clear8(&UARTO_C4, 0xe0, 0x1d); // set bits [4:0] to 0b11101 (0d29)

    setBit8(5, &UARTO_BDH); // one stop bit
    set_and_clear8(&UARTO_BDL, 0x00, 0x7); // set bits [7:0] to 0b111 (0d7)
    set_and_clear8(&UARTO_BDH, 0xf0, 0x0); // set bits [3:0] to 0

    clearBit8(1, &UARTO_C1); // parity disabled
    clearBit8(4, &UARTO_C1); // 8-bit mode

    setBit(9, &SIM_SCGC5); // activate PORTA clock

    set_and_clear(&PORTA_PCR1, 0xfffff8ff, 0x200); // alt2 = 010 (RX)
    set_and_clear(&PORTA_PCR2, 0xfffff8ff, 0x200); // alt2 = 010 (TX)

    setBit8(2, &UARTO_C2); // Receiver enabled
    setBit8(3, &UARTO_C2); // Transmitter enabled
}

void uart_putchar(char c)
{
    while(UARTO_S1 & 0x80 == 0x00) {} // While transmit data buffer is full
    set_and_clear8(&UARTO_D, 0x00, c);
}
