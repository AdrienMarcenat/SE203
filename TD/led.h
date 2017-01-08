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

void led_init();

#endif
