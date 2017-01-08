#include "led.h"

void led_init()
{
    CLOCK_REG  |= 1 << 12 
               |  1 << 13;  // Activates the clock for PORTD and PORTE

    uint32_t GPIO = 1 << 8 | ~(1 << 9 | 1 << 10); // 001 in bits [10:8]

    PORTD_PCR5 &= GPIO; // set PORTD as a GPIO
          
    PORTE_PCR29 &= GPIO; // set PORTE as a GPIO

}
