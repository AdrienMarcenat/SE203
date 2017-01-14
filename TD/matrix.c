#include "reg.h"
#include "bits.h"

void matrix_init()
{
    setBit(9 , &SIM_SCGC5); // Activate PORTA clock
    setBit(10, &SIM_SCGC5); // PORTB
    setBit(11, &SIM_SCGC5); // PORTC
    setBit(12, &SIM_SCGC5); // PORTD

    set_and_clear(&PORTB_PCR0 ,  0xfffff8ff, 0x100); // Set MUX to 001 (GPIO mode)
    set_and_clear(&PORTB_PCR1 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTB_PCR2 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTC_PCR8 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTC_PCR9 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTA_PCR13,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTD_PCR2 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTD_PCR4 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTD_PCR6 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTD_PCR7 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTD_PCR5 ,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTA_PCR12,  0xfffff8ff, 0x100); 
    set_and_clear(&PORTA_PCR4 ,  0xfffff8ff, 0x100); 
    
    setBit(4 , &GPIOA_PDDR); // configure PORTA pin 13 as output
    setBit(12, &GPIOA_PDDR);
    setBit(13, &GPIOA_PDDR);
    setBit(0 , &GPIOB_PDDR);
    setBit(1 , &GPIOB_PDDR);
    setBit(2 , &GPIOB_PDDR);
    setBit(8 , &GPIOC_PDDR);
    setBit(9 , &GPIOC_PDDR);
    setBit(2 , &GPIOD_PDDR);
    setBit(4 , &GPIOD_PDDR);
    setBit(5 , &GPIOD_PDDR);
    setBit(6 , &GPIOD_PDDR);
    setBit(7 , &GPIOD_PDDR);

    setBit(2 , &GPIOB_PCOR); // RST = 0
    setBit(1 , &GPIOB_PSOR); // LAT = 1
    setBit(0 , &GPIOB_PSOR); // SB  = 1
    setBit(8 , &GPIOC_PCOR); // SCK = 0
    setBit(9 , &GPIOC_PCOR); // SDA = 0
    setBit(13, &GPIOA_PCOR); // C0  = 0
    setBit(2 , &GPIOD_PCOR); // C1  = 0
    setBit(4 , &GPIOD_PCOR); // C2  = 0
    setBit(6 , &GPIOD_PCOR); // C3  = 0
    setBit(7 , &GPIOD_PCOR); // C4  = 0
    setBit(5 , &GPIOD_PCOR); // C5  = 0
    setBit(12, &GPIOA_PCOR); // C6  = 0
    setBit(4 , &GPIOA_PCOR); // C7  = 0
}

