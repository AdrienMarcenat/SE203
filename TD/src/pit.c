#include "pit.h"
#include "reg.h"
#include "bits.h"
#include "led.h"
#include "irq.h"

void pit_init()
{
    PIT_ENABLED();

    PIT_MCR     = 0;
    PIT_LTMR64H = 0;
    PIT_LTMR64L = 0;
    PIT_LDVAL0  = 24000000 - 1;
    PIT_LDVAL1  = 0;
    PIT_CVAL0   = 0;
    PIT_CVAL1   = 0;
    PIT_TFLG0   = 0;
    PIT_TFLG1   = 0;
    set_and_clear(&PIT_TCTRL0, 0xfffffff8, 0b011);
    PIT_TCTRL1  = 0;

    irq_enable(22);
}

void PIT_IRQHandler()
{
    LED_R_TOGGLE();
    setBit(0, &PIT_TFLG0);
}
