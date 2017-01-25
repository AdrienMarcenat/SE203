#include "reg.h"
#include "bits.h"
#include "matrix.h"

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

extern uint8_t _binary_image_raw_start;

static void pulse_SCK()
{
    SCK(0);
    asm volatile ("nop");
    SCK(1);
    asm volatile ("nop");
    SCK(0);
}

static void pulse_LAT()
{
    LAT(1);
    asm volatile ("nop");
    LAT(0);
    asm volatile ("nop");
    LAT(1);
}

static void deactivate_rows()
{
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);
}

static void activate_row(int row)
{
    switch(row)
    {
        case 0: { ROW0(1); break; } 
        case 1: { ROW1(1); break; } 
        case 2: { ROW2(1); break; } 
        case 3: { ROW3(1); break; } 
        case 4: { ROW4(1); break; } 
        case 5: { ROW5(1); break; } 
        case 6: { ROW6(1); break; } 
        case 7: { ROW7(1); break; } 
    }
}

static void send_bytes(uint8_t val, int bank)
{
    SB(bank); 
    int i = bank ? 7 : 5; // bank1 stored 8-bit values, bank0 stored 6bit values
    for(; i >= 0; i--)    // most significant bit first
    {
        SDA(getBit8(val, i));
        pulse_SCK();
    }
}

static void mat_set_row(int row, const rgb_color *val)
{
    for(int i = 7; i >= 0; i--) // left LEDs first
    {
        send_bytes(val[i].b, 1);
        send_bytes(val[i].g, 1);
        send_bytes(val[i].r, 1);
    }
    deactivate_rows();
    for(int i = 0; i < 50; i++)  
        asm volatile ("nop"); 
    pulse_LAT();
    activate_row(row);
}

static void init_bank0()
{
    for(int i = 0; i < 18; i++)
    {
        send_bytes(0xff, 0);
    }
    pulse_LAT();
}

void matrix_init()
{
    PORTA_ENABLED();
    PORTB_ENABLED();
    PORTC_ENABLED();
    PORTD_ENABLED();

    SET_AS_GPIO( &PORTB_PCR0 ); 
    SET_AS_GPIO( &PORTB_PCR1 );
    SET_AS_GPIO( &PORTB_PCR2 );
    SET_AS_GPIO( &PORTC_PCR8 );
    SET_AS_GPIO( &PORTC_PCR9 );
    SET_AS_GPIO( &PORTA_PCR13);
    SET_AS_GPIO( &PORTD_PCR2 );
    SET_AS_GPIO( &PORTD_PCR4 );
    SET_AS_GPIO( &PORTD_PCR6 );
    SET_AS_GPIO( &PORTD_PCR7 );
    SET_AS_GPIO( &PORTD_PCR5 );
    SET_AS_GPIO( &PORTA_PCR12);
    SET_AS_GPIO( &PORTA_PCR4 );
    
    SET_AS_OUTPUT(4 , &GPIOA_PDDR);
    SET_AS_OUTPUT(12, &GPIOA_PDDR);
    SET_AS_OUTPUT(13, &GPIOA_PDDR);
    SET_AS_OUTPUT(0 , &GPIOB_PDDR);
    SET_AS_OUTPUT(1 , &GPIOB_PDDR);
    SET_AS_OUTPUT(2 , &GPIOB_PDDR);
    SET_AS_OUTPUT(8 , &GPIOC_PDDR);
    SET_AS_OUTPUT(9 , &GPIOC_PDDR);
    SET_AS_OUTPUT(2 , &GPIOD_PDDR);
    SET_AS_OUTPUT(4 , &GPIOD_PDDR);
    SET_AS_OUTPUT(5 , &GPIOD_PDDR);
    SET_AS_OUTPUT(6 , &GPIOD_PDDR);
    SET_AS_OUTPUT(7 , &GPIOD_PDDR);

    RST(0);
    LAT(1);
    SB(1);
    SCK(0);
    SDA(0);
    deactivate_rows();

    for(int i = 0; i < 6000; i++) // One nop = 18ns, so 6000 nop = ~108ms 
        asm volatile ("nop"); 

    RST(1);

    init_bank0();
}

extern char* trame;

void display_trame()
{
    while(1)
    { 
        for(int i = 0; i < 8; i++)
        {
            rgb_color image[8];
            for(int j = 0; j < 24; j+=3)
            {
                rgb_color color = {trame[8*i+j], trame[8*i+j+1], trame[8*i+j+2]};
                image[j/3] = color; 
            }
            mat_set_row(i, image);
        }
    }
}
