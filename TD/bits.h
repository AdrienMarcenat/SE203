#ifndef BITS_H
#define BITS_H

#include <stdint.h>

void clearBit(int, volatile uint32_t*);
void setBit(int, volatile uint32_t*);
void set_and_clear(volatile uint32_t*, uint32_t, uint32_t);

#endif
