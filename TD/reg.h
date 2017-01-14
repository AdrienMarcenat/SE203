#ifndef REG_H
#define REG_H

#include <stdint.h>

#define SIM_SCGC5   (*(volatile uint32_t *) 0x40048038) // PORTx clocks
#define SIM_SCGC4   (*(volatile uint32_t *) 0x40048034) // UARTx clocks
#define SIM_SOPT2   (*(volatile uint32_t *) 0x40048004)

#define PORTA_PCR1  (*(volatile uint32_t *) 0x40049004)
#define PORTA_PCR2  (*(volatile uint32_t *) 0x40049008)
#define PORTA_PCR4  (*(volatile uint32_t *) 0x40049010)
#define PORTA_PCR12 (*(volatile uint32_t *) 0x40049030)
#define PORTA_PCR13 (*(volatile uint32_t *) 0x40049034)

#define PORTB_PCR0  (*(volatile uint32_t *) 0x4004a000)
#define PORTB_PCR1  (*(volatile uint32_t *) 0x4004a004)
#define PORTB_PCR2  (*(volatile uint32_t *) 0x4004a008)

#define PORTC_PCR8  (*(volatile uint32_t *) 0x4004b020)
#define PORTC_PCR9  (*(volatile uint32_t *) 0x4004b024)

#define PORTD_PCR2  (*(volatile uint32_t *) 0x4004c008) 
#define PORTD_PCR4  (*(volatile uint32_t *) 0x4004c010) 
#define PORTD_PCR5  (*(volatile uint32_t *) 0x4004c014) 
#define PORTD_PCR6  (*(volatile uint32_t *) 0x4004c018) 
#define PORTD_PCR7  (*(volatile uint32_t *) 0x4004c01c) 

#define PORTE_PCR29 (*(volatile uint32_t *) 0x4004d074)

#define GPIOA_PDDR  (*(volatile uint32_t *) 0x400ff014)
#define GPIOB_PDDR  (*(volatile uint32_t *) 0x400ff054)
#define GPIOC_PDDR  (*(volatile uint32_t *) 0x400ff094)
#define GPIOD_PDDR  (*(volatile uint32_t *) 0x400ff0d4)
#define GPIOE_PDDR  (*(volatile uint32_t *) 0x400ff114)

#define GPIOD_PCOR  (*(volatile uint32_t *) 0x400ff0c8)
#define GPIOE_PCOR  (*(volatile uint32_t *) 0x400ff108)
#define GPIOD_PSOR  (*(volatile uint32_t *) 0x400ff0c4)
#define GPIOE_PSOR  (*(volatile uint32_t *) 0x400ff104)
#define GPIOD_PTOR  (*(volatile uint32_t *) 0x400ff0cc)
#define GPIOE_PTOR  (*(volatile uint32_t *) 0x400ff10c)

#define UARTO_BDH (*(volatile uint8_t *) 0x4006a000)
#define UARTO_BDL (*(volatile uint8_t *) 0x4006a001)
#define UARTO_C1  (*(volatile uint8_t *) 0x4006a002)
#define UARTO_C2  (*(volatile uint8_t *) 0x4006a003)
#define UARTO_C4  (*(volatile uint8_t *) 0x4006a00a)
#define UARTO_S1  (*(volatile uint8_t *) 0x4006a004)
#define UARTO_D   (*(volatile uint8_t *) 0x4006a007)


#endif

