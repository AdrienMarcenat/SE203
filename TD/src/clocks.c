#include "clocks.h"
#include "reg.h"
#include "bits.h"

void clocks_init()
{
    SIM_COPC = 0; // disable watchdog

    MCG_C2 = 0x2C;
    MCG_C1 = 0xa8;
    while(getBit8(MCG_S, 1) == 0);
    while(getBit8(MCG_S, 4) > 0);
    while(((MCG_S >> 2) & 0x3) != 0x2);
    MCG_C5 = 0x03;
    MCG_C6 = 0x40;
    while(getBit8(MCG_S, 5) == 0);
    while(getBit8(MCG_S, 6) == 0);
    MCG_C1 = 0x28;
    while(((MCG_S >> 2) & 0x3) != 0x3);

    SIM_CLKDIV1 = (1 << 16); /* Bus, flash clock = 24 MHz
                                Core, Platform, System clock = 48 MHz */

}
