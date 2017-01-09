#ifndef LED_H
#define LED_H

#include <stdint.h>

#define CLOCK_REG   (*(volatile uint32_t *) 0x40048038)
#define PORTD_PCR5  (*(volatile uint32_t *) 0x4004c014)
#define PORTE_PCR29 (*(volatile uint32_t *) 0x4004d074)
#define GPIOD_PDDR  (*(volatile uint32_t *) 0x400ff0d4)
#define GPIOE_PDDR  (*(volatile uint32_t *) 0x400ff114)
#define GPIOD_PCOR  (*(volatile uint32_t *) 0x400ff0c8)
#define GPIOE_PCOR  (*(volatile uint32_t *) 0x400ff108)
#define GPIOD_PSOR  (*(volatile uint32_t *) 0x400ff0c4)
#define GPIOE_PSOR  (*(volatile uint32_t *) 0x400ff104)
#define GPIOD_PTOR  (*(volatile uint32_t *) 0x400ff0cc)
#define GPIOE_PTOR  (*(volatile uint32_t *) 0x400ff10c)

void led_init();
void led_g_on();
void led_g_off();
void led_g_toggle();
void led_r_on();
void led_r_off();
void led_r_toggle();

#endif
