#ifndef REG_H
#define REG_H

#include <stdint.h>

#define SIM_SCGC6   (*(volatile uint32_t *) 0x4004803c) // PIT   clock
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

#define PORTC_PCR3  (*(volatile uint32_t *) 0x4004b00c)
#define PORTC_PCR8  (*(volatile uint32_t *) 0x4004b020)
#define PORTC_PCR9  (*(volatile uint32_t *) 0x4004b024)

#define PORTD_PCR2  (*(volatile uint32_t *) 0x4004c008) 
#define PORTD_PCR4  (*(volatile uint32_t *) 0x4004c010) 
#define PORTD_PCR5  (*(volatile uint32_t *) 0x4004c014) 
#define PORTD_PCR6  (*(volatile uint32_t *) 0x4004c018) 
#define PORTD_PCR7  (*(volatile uint32_t *) 0x4004c01c) 

#define PORTE_PCR29 (*(volatile uint32_t *) 0x4004d074)


#define GPIOA_PSOR  (*(volatile uint32_t *) 0x400ff004)
#define GPIOA_PCOR  (*(volatile uint32_t *) 0x400ff008)
#define GPIOA_PTOR  (*(volatile uint32_t *) 0x400ff00c)
#define GPIOA_PDDR  (*(volatile uint32_t *) 0x400ff014)

#define GPIOB_PSOR  (*(volatile uint32_t *) 0x400ff044)
#define GPIOB_PCOR  (*(volatile uint32_t *) 0x400ff048)
#define GPIOB_PTOR  (*(volatile uint32_t *) 0x400ff04c)
#define GPIOB_PDDR  (*(volatile uint32_t *) 0x400ff054)

#define GPIOC_PSOR  (*(volatile uint32_t *) 0x400ff084)
#define GPIOC_PCOR  (*(volatile uint32_t *) 0x400ff088)
#define GPIOC_PTOR  (*(volatile uint32_t *) 0x400ff08c)
#define GPIOC_PDDR  (*(volatile uint32_t *) 0x400ff094)

#define GPIOD_PSOR  (*(volatile uint32_t *) 0x400ff0c4)
#define GPIOD_PCOR  (*(volatile uint32_t *) 0x400ff0c8)
#define GPIOD_PTOR  (*(volatile uint32_t *) 0x400ff0cc)
#define GPIOD_PDDR  (*(volatile uint32_t *) 0x400ff0d4)

#define GPIOE_PSOR  (*(volatile uint32_t *) 0x400ff104)
#define GPIOE_PCOR  (*(volatile uint32_t *) 0x400ff108)
#define GPIOE_PTOR  (*(volatile uint32_t *) 0x400ff10c)
#define GPIOE_PDDR  (*(volatile uint32_t *) 0x400ff114)


#define UART0_BDH (*(volatile uint8_t *) 0x4006a000)
#define UART0_BDL (*(volatile uint8_t *) 0x4006a001)
#define UART0_C1  (*(volatile uint8_t *) 0x4006a002)
#define UART0_C2  (*(volatile uint8_t *) 0x4006a003)
#define UART0_S1  (*(volatile uint8_t *) 0x4006a004)
#define UART0_S2  (*(volatile uint8_t *) 0x4006a005)
#define UART0_C3  (*(volatile uint8_t *) 0x4006a006)
#define UART0_D   (*(volatile uint8_t *) 0x4006a007)
#define UART0_MA1 (*(volatile uint8_t *) 0x4006a008)
#define UART0_MA2 (*(volatile uint8_t *) 0x4006a009)
#define UART0_C4  (*(volatile uint8_t *) 0x4006a00a)
#define UART0_C5  (*(volatile uint8_t *) 0x4006a00b)


#define VTOR      (*(volatile uint32_t *) 0xe000ed08) 
#define NVIC_ISER (*(volatile uint32_t *) 0xe000e100) 
#define NVIC_ICER (*(volatile uint32_t *) 0xe000e180) 


#define PIT_MCR     (*(volatile uint32_t *) 0x40037000) 
#define PIT_LTMR64H (*(volatile uint32_t *) 0x400370e0) 
#define PIT_LTMR64L (*(volatile uint32_t *) 0x400370e4) 
#define PIT_LDVAL0  (*(volatile uint32_t *) 0x40037100) 
#define PIT_CVAL0   (*(volatile uint32_t *) 0x40037104) 
#define PIT_TCTRL0  (*(volatile uint32_t *) 0x40037108) 
#define PIT_TFLG0   (*(volatile uint32_t *) 0x4003710c) 
#define PIT_LDVAL1  (*(volatile uint32_t *) 0x40037110) 
#define PIT_CVAL1   (*(volatile uint32_t *) 0x40037114) 
#define PIT_TCTRL1  (*(volatile uint32_t *) 0x40037118) 
#define PIT_TFLG1   (*(volatile uint32_t *) 0x4003711c) 


#define SET_AS_GPIO(reg)        do{ set_and_clear(reg, 0xfffff8ff, 0x100); }while(0)
#define SET_AS_OUTPUT(pin, reg) do{ setBit(pin, reg); }while(0)
#define SET_AS_INPUT(pin, reg)  do{ clearBit(pin, reg); }while(0)

#define PORTA_ENABLED() do{ setBit(9 , &SIM_SCGC5); }while(0)
#define PORTB_ENABLED() do{ setBit(10, &SIM_SCGC5); }while(0)
#define PORTC_ENABLED() do{ setBit(11, &SIM_SCGC5); }while(0)
#define PORTD_ENABLED() do{ setBit(12, &SIM_SCGC5); }while(0)
#define PORTE_ENABLED() do{ setBit(13, &SIM_SCGC5); }while(0)

#define UART0_ENABLED() do{ setBit(10, &SIM_SCGC4); }while(0)
#define PIT_ENABLED()   do{ setBit(23, &SIM_SCGC6); }while(0)

#endif
