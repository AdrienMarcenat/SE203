#include "clocks.h"
#include "reg.h"
#include "bits.h"

void clocks_init()
{
    SIM_COPC = 0; // disable watchdog
}
