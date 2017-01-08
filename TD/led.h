#include <stdint.h>

#define CLOCK_REG (*(volatile uint32_t *) 0x40048038)
#define PORTD_PCR5 (*(volatile uint32_t *) 0x4004c014)
#define PORTE_PCR29 (*(volatile uint32_t *) 0x4004d074)
