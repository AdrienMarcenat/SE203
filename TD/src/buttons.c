#include "reg.h"
#include "bits.h"
#include "irq.h"
#include "led.h"

void button_init()
{
    PORTD_ENABLED();
    set_and_clear( &PORTC_PCR3, 0xfff0f8fc, 0x000a0103);
    SET_AS_INPUT(3, &GPIOC_PDDR);

    irq_enable(31);
}

void PCMCD_IRQHandler()
{
    LED_R_TOGGLE();
    setBit(24, &PORTC_PCR3);
}
