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
    test_image();

    return 0;
}

