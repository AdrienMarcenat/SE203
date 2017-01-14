#ifndef LED_H
#define LED_H

void led_init();

#define LED_G_ON()     setBit(5, &GPIOD_PCOR);
#define LED_G_OFF()    setBit(5, &GPIOD_PSOR);
#define LED_G_TOGGLE() setBit(5, &GPIOD_PTOR);
#define LED_R_ON()     setBit(29, &GPIOE_PCOR);
#define LED_R_OFF()    setBit(29, &GPIOE_PSOR);
#define LED_R_TOGGLE() setBit(29, &GPIOE_PTOR);

#endif
