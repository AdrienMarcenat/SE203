#include "led.h"

void led_init()
{
    CLOCK_REG  |= 1 << 12 
               |  1 << 13;  // Activates the clock for PORTD and PORTE

    uint32_t GPIO = 1 << 8 | ~(1 << 9 | 1 << 10); // 001 in bits [10:8]

    PORTD_PCR5  &= GPIO; // set pin PTD5 as a GPIO      
    PORTE_PCR29 &= GPIO; // set pin PTE29 as a GPIO

    GPIOD_PDDR |= 1 << 5 ; // set pin PTD5 as output
    GPIOE_PDDR |= 1 << 29; // set pin PTE29 as output
}
