#include "uart.h"
#include "bits.h"

void uart_init()
{
    setBit(26, &SIM_SOPT2); // use MCGPLLCLK/2 clock for UART0
    clearBit(27, &SIM_SOPT2);
    setBit(10, &SIM_SCGC4); // clock enabled for UART0

    set_and_clear(&UARTO_C4, 0x1d, 0x2); // set bits [4:0] to 11101 (29)
}
