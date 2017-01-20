#ifndef LED_H
#define LED_H

#include "bits.h"
#include "reg.h"

void led_init();

#define LED_R_ON()     do{setBit(29, &GPIOE_PCOR);}while(0)
#define LED_R_OFF()    do{setBit(29, &GPIOE_PSOR);}while(0)
#define LED_R_TOGGLE() do{setBit(29, &GPIOE_PTOR);}while(0)

#endif
