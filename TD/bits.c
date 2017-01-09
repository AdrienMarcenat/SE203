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
    
