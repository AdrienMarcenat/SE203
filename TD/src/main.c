#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"
#include "irq.h"
#include "buttons.h"

int main()
{
    clocks_init();
    matrix_init();
    irq_init();
    button_init();
    led_init();
    uart_init();

    display_trame();

    return 0;
}

