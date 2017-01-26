#include "pit.h"
#include "reg.h"
#include "bits.h"

void pit_init()
{
    PIT_MCR     = 0;
    PIT_LTMR64H = 0;
    PIT_LTMR64L = 0;
    PIT_LDVAL0  = 240000000;
    PIT_LDVAL0  = 0;
    PIT_CVAL0   = 0;
    PIT_CVAL1   = 0;
    PIT_TFLG0   = 0;
    PIT_TFLG1   = 0;
    set_and_clear(&PIT_TCTRL0, 0xfffffff8, 0b011);
    set_and_clear(&PIT_TCTRL1, 0xfffffff8, 0b011);
}
