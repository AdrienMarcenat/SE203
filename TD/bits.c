#include "bits.h"

void clearBit(int bit, volatile uint32_t* reg)
{
    *reg &= ~( 1 << bit);
}

void setBit(int bit, volatile uint32_t* reg)
{
    *reg |= 1 << bit;
}

void set_and_clear(volatile uint32_t* reg, uint32_t to_set, uint32_t to_clear)
{
    *reg = (*reg & ~to_clear) | to_set;  
}

void clearBit8(int bit, volatile uint8_t* reg)
{
    *reg &= ~( 1 << bit);
}

void setBit8(int bit, volatile uint8_t* reg)
{
    *reg |= 1 << bit;
}

void set_and_clear8(volatile uint8_t* reg, uint8_t to_set, uint8_t to_clear)
{
    *reg = (*reg & ~to_clear) | to_set;  
}
    
