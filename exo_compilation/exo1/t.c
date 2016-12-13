#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int32_t x = 34;
int8_t y_int8;
short y_short;
int32_t y_int32;
long long y_long_long;

const char mesg[] = "Hello World!\n";

int main() 
{
    static uint8_t z;
    uint16_t t;

    y_int8 = 12;
    z = z + 1;
    t = y_int8 + z;

    printf(mesg);
    printf("x = %d, y = %d, z = %d, t = %d\n", x, y_int8, z, t);
    
    return 0;
}
