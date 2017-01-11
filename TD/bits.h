#ifndef BITS_H
#define BITS_H

#include <stdint.h>

void clearBit(int, volatile uint32_t*);
void setBit(int, volatile uint32_t*);
void set_and_clear(volatile uint32_t*, uint32_t, uint32_t);
int getBit(volatile uint32_t*, int);

void clearBit8(int, volatile uint8_t*);
void setBit8(int, volatile uint8_t*);
void set_and_clear8(volatile uint8_t*, uint8_t, uint8_t);
int getBit8(volatile uint8_t*, int);

#endif
