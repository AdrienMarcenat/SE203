#include "led.h"

void led_init()
{
    CLOCK_REG = CLOCK_REG | 1 << 12 
                          | 1 << 13; 
}
