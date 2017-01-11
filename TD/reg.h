#ifndef REG_H
#define REG_H

#include <stdint.h>

#define SIM_SCGC5   (*(volatile uint32_t *) 0x40048038) // PORTx clocks
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

#define SIM_SOPT2 (*(volatile uint32_t *) 0x40048004)
#define SIM_SCGC4 (*(volatile uint32_t *) 0x40048034) // UARTx clocks
#define UARTO_C4  (*(volatile uint8_t *) 0x4006a00a)
#define UARTO_BDH (*(volatile uint8_t *) 0x4006a000)
#define UARTO_BDL (*(volatile uint8_t *) 0x4006a001)
#define UARTO_C1  (*(volatile uint8_t *) 0x4006a002)
#define UARTO_C2  (*(volatile uint8_t *) 0x4006a003)

#define PORTA_PCR1 (*(volatile uint32_t *) 0x40049004)
#define PORTA_PCR2 (*(volatile uint32_t *) 0x40049008)

#endif


