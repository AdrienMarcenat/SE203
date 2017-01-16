#include "reg.h"
#include "bits.h"
#include "matrix.h"

extern uint8_t _binary_image_raw_start;

void matrix_init()
{
    ACTIVATE_CLOCK(9 ); // Activate PORTA clock
    ACTIVATE_CLOCK(10); // PORTB
    ACTIVATE_CLOCK(11); // PORTC
    ACTIVATE_CLOCK(12); // PORTD

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

void pulse_SCK()
{
    SCK(0);
    asm volatile ("nop");
    SCK(1);
    asm volatile ("nop");
    SCK(0);
}

void pulse_LAT()
{
    LAT(1);
    asm volatile ("nop");
    LAT(0);
    asm volatile ("nop");
    LAT(1);
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

void send_bytes(uint8_t val, int bank)
{
    SB(bank); 
    int i = bank ? 7 : 5; // bank1 stored 8-bit values, bank0 stred 6bit values
    for(; i >= 0; i--)    // most significant bit first
   {
        SDA(getBit8(val, i));
        pulse_SCK();
    }
}

void mat_set_row(int row, const rgb_color *val)
{
    for(int i = 7; i >= 0; i--) // left LEDs first
    {
        send_bytes(val[i].b, 1);
        send_bytes(val[i].g, 1);
        send_bytes(val[i].r, 1);
    }
    deactivate_rows();
    activate_row(row);
    pulse_LAT();
    
}

void init_bank0()
{
    for(int i = 0; i < 24; i++)
    {
        send_bytes(0xff, 0);
    }
    pulse_LAT();
}

void test_pixels()
{
    rgb_color red[8];
    rgb_color green[8];
    rgb_color blue[8];
    uint8_t gradient = 0;
    
    for(int i = 0; i < 8; i++)
    {
        gradient    = 255*i/8 + 10;
        rgb_color r = {gradient, 0, 0};
        rgb_color g = {0, gradient, 0};
        rgb_color b = {0, 0, gradient};
        red[i]   = r;
        green[i] = g;
        blue[i]  = b;
    }

    // Display a succession of red/green/blue line, with a color gradient
    while(1)
    {
        mat_set_row(0, red);
        mat_set_row(1, green);
        mat_set_row(2, blue);
        mat_set_row(3, red);
        mat_set_row(4, green);
        mat_set_row(5, blue);
        mat_set_row(6, red);
        mat_set_row(7, green);
    }
}

void test_image()
{
    rgb_color lines[8][8];
    
    uint8_t* add = &_binary_image_raw_start;
    for(int j = 0; j < 8; j++)
    {
        fill_line(lines[j], add);
        add += 24;
    }

    while(1)
    {
        mat_set_row(0, lines[0]);
        mat_set_row(1, lines[1]);
        mat_set_row(2, lines[2]);
        mat_set_row(3, lines[3]);
        mat_set_row(4, lines[4]);
        mat_set_row(5, lines[5]);
        mat_set_row(6, lines[6]);
        mat_set_row(7, lines[7]);
    }
}

void fill_line(rgb_color* line, uint8_t* add)
{
    for(int j = 0; j < 8; j++)
    {
        rgb_color color = {*add, *(add+1), *(add+2)};
        line[j] = color; 
        add += 3;
    }
}
