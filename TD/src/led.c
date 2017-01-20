#include "led.h"
#include "bits.h"
#include "reg.h"

void led_init()
{
    PORTE_ENABLED(); 
    SET_AS_GPIO( &PORTE_PCR29);
    SET_AS_OUTPUT(29, &GPIOE_PDDR);
    LED_R_ON(); 
}
