#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"

int main()
{
    clocks_init();

    matrix_init();

    return 0;
}

