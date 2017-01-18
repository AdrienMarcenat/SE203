#include "reg.h"
#include "bits.h"
#include "irq.h"
#include "led.h"

void button_init()
{
    ACTIVATE_CLOCK(12);
    SET_AS_GPIO( &PORTC_PCR3 );
    set_and_clear( &PORTC_PCR3, 0xfff0ffff, 0x000a0000); // Interrupt on falling edge   
    setBit(0, &PORTC_PCR3); // Pulldown/Pullup enabled
    setBit(1, &PORTC_PCR3); // Pullup selected
    SET_AS_INPUT(3, &GPIOC_PDDR);

    irq_enable(31);
}

void PCMCD_IRQHandler()
{
    LED_R_TOGGLE();
}
