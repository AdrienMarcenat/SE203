#include "reg.h"
#include "bits.h"
#include "matrix.h"

void matrix_init()
{
    SET_AS_OUTPUT(9 , &SIM_SCGC5); // Activate PORTA clock
    SET_AS_OUTPUT(10, &SIM_SCGC5); // PORTB
    SET_AS_OUTPUT(11, &SIM_SCGC5); // PORTC
    SET_AS_OUTPUT(12, &SIM_SCGC5); // PORTD

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
    
    SET_AS_OUTPUT(4 , &GPIOA_PDDR); // configure PORTA pin 13 as output
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
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);

    for(int i = 0; i < 6000; i++) // One nop = 18ns, so 6000 nop = ~108ms 
        asm volatile ("nop"); 

    RST(1);
}

void pulse_SCK()
{
    SCK(0);
    asm volatile ("nop");
    SCK(1);
    asm volatile ("nop");
    SCK(0);
    asm volatile ("nop");
}

void pulse_LAT()
{
    LAT(1);
    asm volatile ("nop");
    LAT(0);
    asm volatile ("nop");
    LAT(1);
    asm volatile ("nop");
}

void deactivate_rows()
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

void activate_row(int row)
{
    if(row == 0) { ROW0(1);}
    else if(row == 1) { ROW1(1);}
    else if(row == 2) { ROW1(2);}
    else if(row == 3) { ROW1(3);}
    else if(row == 4) { ROW1(4);}
    else if(row == 5) { ROW1(5);}
    else if(row == 6) { ROW1(6);}
    else if(row == 7) { ROW1(7);}
}

void send_bytes(uint8_t val, int bank)
{
    SB(bank); 
    for(int i = 7; i >= 0; i--)
    {
        SDA(getBit8(val, i));
        pulse_SCK();
    }
}

void mat_set_row(int row, const rgb_color *val)
{
    for(int i = 7; i >= 0; i--)
    {
        send_bytes(val[i].r, 1);
        send_bytes(val[i].g, 1);
        send_bytes(val[i].b, 1);
    }
    activate_row(row);
    pulse_LAT();
}
