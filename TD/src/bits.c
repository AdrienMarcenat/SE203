#include "bits.h"

void clearBit(int bit, volatile uint32_t* reg)
{
    *reg &= ~( 1 << bit);
}

void setBit(int bit, volatile uint32_t* reg)
{
    *reg |= 1 << bit;
}

void set_and_clear(volatile uint32_t* reg, uint32_t mask, uint32_t value)
{
    *reg &= (mask  | value);  
    *reg |= (~mask & value);
}

void clearBit8(int bit, volatile uint8_t* reg)
{
    *reg &= ~( 1 << bit);
}

void setBit8(int bit, volatile uint8_t* reg)
{
    *reg |= 1 << bit;
}

void set_and_clear8(volatile uint8_t* reg, uint8_t mask, uint8_t value)
{
    *reg &= (mask  | value);  
    *reg |= (~mask & value);
}
     
int getBit(volatile uint32_t reg, int bit)
{
    return (reg >> bit) & 1;
}

int getBit8(volatile uint8_t reg, int bit)
{
    return (reg >> bit) & 1;
}
