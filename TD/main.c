#include "led.h"
#include "clocks.h"
#include "uart.h"

int main()
{
    clocks_init();
    led_init();
    uart_init();
    led_g_toggle();

    int loop = 3*(1 << 20);

    while(1)
    {
        for (int i=0; i<loop; i++)
            asm volatile("nop");
        led_g_toggle();
        led_r_toggle();
    }

    return 0;
}

