#ifndef MATRIX_H
#define MATRIX_H

#include "reg.h"

void matrix_init();

#define RST(x) if(x) setBit(2, &GPIOB_PSOR); \
               else  setBit(2, &GPIOB_PCOR); 
#define SB(x)  if(x) setBit(0, &GPIOB_PSOR); \
               else  setBit(0, &GPIOB_PCOR); 
#define LAT(x) if(x) setBit(1, &GPIOB_PSOR); \
               else  setBit(1, &GPIOB_PCOR); 
#define SCK(x) if(x) setBit(8, &GPIOC_PSOR); \
               else  setBit(8, &GPIOC_PCOR); 
#define SDA(x) if(x) setBit(9, &GPIOC_PSOR); \
               else  setBit(9, &GPIOC_PCOR); 
#define ROW0(x) if(x) setBit(13, &GPIOA_PSOR); \
                else  setBit(13, &GPIOA_PCOR); 
#define ROW1(x) if(x) setBit(2, &GPIOD_PSOR); \
                else  setBit(2, &GPIOD_PCOR); 
#define ROW2(x) if(x) setBit(4, &GPIOD_PSOR); \
                else  setBit(4, &GPIOD_PCOR); 
#define ROW3(x) if(x) setBit(6, &GPIOD_PSOR); \
                else  setBit(6, &GPIOD_PCOR); 
#define ROW4(x) if(x) setBit(7, &GPIOD_PSOR); \
                else  setBit(7, &GPIOD_PCOR); 
#define ROW5(x) if(x) setBit(5, &GPIOD_PSOR); \
                else  setBit(5, &GPIOD_PCOR); 
#define ROW6(x) if(x) setBit(12, &GPIOA_PSOR); \
                else  setBit(12, &GPIOA_PCOR); 
#define ROW7(x) if(x) setBit(4, &GPIOA_PSOR); \
                else  setBit(4, &GPIOA_PCOR); 

#define pulse_SCK() SCK(0); \
                    asm volatile ("nop"); \
                    SCK(1); \
                    asm volatile ("nop"); \
                    SCK(0); \
                    asm volatile ("nop"); \
#define pulse_LAT() LAT(1); \
                    asm volatile ("nop"); \
                    LAT(0); \
                    asm volatile ("nop"); \
                    LAT(1); \
                    asm volatile ("nop"); \
#endif
