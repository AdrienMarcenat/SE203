#include "led.h"
#include "clocks.h"
#include "uart.h"

int main()
{
    clocks_init();
    led_init();
    uart_init();
    led_g_toggle();

    uart_checksum();

    led_g_toggle(); // to check if the uart has received the sum
    
    return 0;
}

