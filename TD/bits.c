#include "bits.h"

void clearBit(int bit, volatile uint32_t* reg)
{
    *reg &= ~( 1 << bit);
}

void setBit(int bit, volatile uint32_t* reg)
{
    *reg |= 1 << bit;
}
