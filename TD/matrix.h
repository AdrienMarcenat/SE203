#ifndef MATRIX_H
#define MATRIX_H

#include "reg.h"

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color;

void matrix_init();
void deactivate_rows();
void activate_row(int row);
void pulse_SCK();
void pulse_LAT();
void send_bytes(uint8_t, int);
void mat_set_row(int, const rgb_color*);
void init_bank0();
void test_pixels();
void test_image();
void fill_line(rgb_color*, uint8_t*);

#define RST(x) do{ if(x) setBit(2, &GPIOB_PSOR); \
                   else  setBit(2, &GPIOB_PCOR); }while(0)

#define SB(x)  do{ if(x) setBit(0, &GPIOB_PSOR); \
                   else  setBit(0, &GPIOB_PCOR); }while(0) 

#define LAT(x) do{ if(x) setBit(1, &GPIOB_PSOR); \
                   else  setBit(1, &GPIOB_PCOR); }while(0) 

#define SCK(x) do{ if(x) setBit(8, &GPIOC_PSOR); \
                   else  setBit(8, &GPIOC_PCOR); }while(0) 

#define SDA(x) do{ if(x) setBit(9, &GPIOC_PSOR); \
                   else  setBit(9, &GPIOC_PCOR); }while(0) 

#define ROW0(x) do{ if(x) setBit(13, &GPIOA_PSOR); \
                    else  setBit(13, &GPIOA_PCOR);}while(0) 
 
#define ROW1(x) do{ if(x) setBit(2 , &GPIOD_PSOR); \
                    else  setBit(2 , &GPIOD_PCOR); }while(0) 

#define ROW2(x) do{ if(x) setBit(4 , &GPIOD_PSOR); \
                    else  setBit(4 , &GPIOD_PCOR); }while(0) 

#define ROW3(x) do{ if(x) setBit(6 , &GPIOD_PSOR); \
                    else  setBit(6 , &GPIOD_PCOR); }while(0) 

#define ROW4(x) do{ if(x) setBit(7 , &GPIOD_PSOR); \
                    else  setBit(7 , &GPIOD_PCOR); }while(0) 

#define ROW5(x) do{ if(x) setBit(5 , &GPIOD_PSOR); \
                    else  setBit(5 , &GPIOD_PCOR); }while(0) 

#define ROW6(x) do{ if(x) setBit(12, &GPIOA_PSOR); \
                    else  setBit(12, &GPIOA_PCOR); }while(0) 

#define ROW7(x) do{ if(x) setBit(4 , &GPIOA_PSOR); \
                    else  setBit(4 , &GPIOA_PCOR); }while(0) 


#endif
