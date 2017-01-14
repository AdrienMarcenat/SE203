#include "led.h"
#include "bits.h"
#include "reg.h"

void led_init()
{
    setBit(12, &SIM_SCGC5); // activate PORTD clock
    setBit(13, &SIM_SCGC5); // activate PORTE clock
    
    set_and_clear(&PORTD_PCR5,  0xfffff8ff, 0x100); // Set MUX to 001 (GPIO mode)
    set_and_clear(&PORTE_PCR29, 0xfffff8ff, 0x100); 

    setBit(5,  &GPIOD_PDDR); // configure pin as output
    setBit(29, &GPIOE_PDDR);
    
    setBit(5,  &GPIOD_PCOR); // light the led
    setBit(29, &GPIOE_PCOR);
}

void led_g_on()
{
    setBit(5, &GPIOD_PCOR);
}

void led_g_off()
{
    setBit(5, &GPIOD_PSOR);
}

void led_g_toggle()
{
    setBit(5, &GPIOD_PTOR);
}

void led_r_on()
{
    setBit(29, &GPIOE_PCOR);
}

void led_r_off()
{
    setBit(29, &GPIOE_PSOR);
}

void led_r_toggle()
{
    setBit(29, &GPIOE_PTOR);
}
