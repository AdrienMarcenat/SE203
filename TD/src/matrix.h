#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h> 

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color;

void matrix_init();
void test_pixels();
void test_image();

#endif
