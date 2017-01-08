#include "led.h"

void clearBit(int bit, volatile uint32_t* reg)
{
    *reg &= ~( 1 << bit);
}

void setBit(int bit, volatile uint32_t* reg)
{
    *reg |= 1 << bit;
}

void led_init()
{
    setBit(12, &CLOCK_REG);
    setBit(13, &CLOCK_REG);

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
