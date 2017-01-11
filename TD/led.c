#include "led.h"
#include "bits.h"
#include "reg.h"

void led_init()
{
    setBit(12, &SIM_SCGC5);
    setBit(13, &SIM_SCGC5);

    clearBit(10, &PORTD_PCR5);       
    clearBit(9, &PORTD_PCR5);       
    setBit(8, &PORTD_PCR5);
    clearBit(10, &PORTE_PCR29);       
    clearBit(9, &PORTE_PCR29);       
    setBit(8, &PORTE_PCR29);       

    setBit(5, &GPIOD_PDDR);
    setBit(29, &GPIOE_PDDR);
    
    setBit(5, &GPIOD_PCOR);
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
