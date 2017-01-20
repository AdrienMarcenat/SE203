#include "led.h"
#include "bits.h"
#include "reg.h"

void led_init()
{
    PORTD_ENABLED(); 
    PORTE_ENABLED(); 
    
    SET_AS_GPIO( &PORTD_PCR5 );
    SET_AS_GPIO( &PORTE_PCR29);

    SET_AS_OUTPUT(5 , &GPIOD_PDDR);
    SET_AS_OUTPUT(29, &GPIOD_PDDR);
    
    setBit(5,  &GPIOD_PCOR); // light the led
    setBit(29, &GPIOE_PCOR);
}
