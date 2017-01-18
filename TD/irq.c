#include "irq.h"

extern char _start, _stack;

MAKE_DEFAULT_HANDLER(NMI      );
MAKE_DEFAULT_HANDLER(HardFault);
MAKE_DEFAULT_HANDLER(SVC      );
MAKE_DEFAULT_HANDLER(PendSV   );
MAKE_DEFAULT_HANDLER(SysTick  );
MAKE_DEFAULT_IRQHANDLER(DMA0  );
MAKE_DEFAULT_IRQHANDLER(DMA1  );
MAKE_DEFAULT_IRQHANDLER(DMA2  );
MAKE_DEFAULT_IRQHANDLER(DMA3  );
MAKE_DEFAULT_IRQHANDLER(FTFA  );
MAKE_DEFAULT_IRQHANDLER(PMC   );
MAKE_DEFAULT_IRQHANDLER(LLWU  );
MAKE_DEFAULT_IRQHANDLER(I2C0  );
MAKE_DEFAULT_IRQHANDLER(I2C1  );
MAKE_DEFAULT_IRQHANDLER(SPI0  );
MAKE_DEFAULT_IRQHANDLER(SPI1  );
MAKE_DEFAULT_IRQHANDLER(UART0 );
MAKE_DEFAULT_IRQHANDLER(UART1 );
MAKE_DEFAULT_IRQHANDLER(UART2 );
MAKE_DEFAULT_IRQHANDLER(ADC0  );
MAKE_DEFAULT_IRQHANDLER(CMP0  );
MAKE_DEFAULT_IRQHANDLER(TPM0  );
MAKE_DEFAULT_IRQHANDLER(TPM1  );
MAKE_DEFAULT_IRQHANDLER(TPM2  );
MAKE_DEFAULT_IRQHANDLER(RTC0  );
MAKE_DEFAULT_IRQHANDLER(RTC1  );
MAKE_DEFAULT_IRQHANDLER(PIT   );
MAKE_DEFAULT_IRQHANDLER(I2S0  );
MAKE_DEFAULT_IRQHANDLER(USBOTG);
MAKE_DEFAULT_IRQHANDLER(DAC0  );
MAKE_DEFAULT_IRQHANDLER(TSIO  );
MAKE_DEFAULT_IRQHANDLER(MCG   );
MAKE_DEFAULT_IRQHANDLER(LPTMR0);
MAKE_DEFAULT_IRQHANDLER(SLCD  );
MAKE_DEFAULT_IRQHANDLER(PCMA  );
MAKE_DEFAULT_IRQHANDLER(PCMCD );

void *vector_table[] = {
    // Stack and Reset Handler
    &_stack,            /* Top of stack  */
    &_start,            /* Reset handler */

    // ARM internal exceptions
    NMI_Handler,        /* NMI handler */
    HardFault_Handler,  /* Hard Fault handler */
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    SVC_Handler,        /* SVC handler */
    0,                  /* Reserved */
    0,                  /* Reserved */
    PendSV_Handler,     /* Pending SVC handler */
    SysTick_Handler,    /* SysTick hanlder */

    // KL46 External interrupts
    DMA0_IRQHandler,         /* DMA0 interrupt */
    DMA1_IRQHandler,         /* DMA1 interrupt */
    DMA2_IRQHandler,         /* DMA2 interrupt */
    DMA3_IRQHandler,         /* DMA2 interrupt */
    0,
    FTFA_IRQHandler  ,
    PMC_IRQHandler   ,
    LLWU_IRQHandler  ,
    I2C0_IRQHandler  ,
    I2C1_IRQHandler  ,
    SPI0_IRQHandler  ,
    SPI1_IRQHandler  ,
    UART0_IRQHandler ,
    UART1_IRQHandler ,
    UART2_IRQHandler ,
    ADC0_IRQHandler  ,
    CMP0_IRQHandler  ,
    TPM0_IRQHandler  ,
    TPM1_IRQHandler  ,
    TPM2_IRQHandler  ,
    RTC0_IRQHandler  ,
    RTC1_IRQHandler  ,
    PIT_IRQHandler   ,
    I2S0_IRQHandler  ,
    USBOTG_IRQHandler,
    DAC0_IRQHandler  ,
    TSIO_IRQHandler  ,
    MCG_IRQHandler   ,
    LPTMR0_IRQHandler,
    SLCD_IRQHandler  ,
    PCMA_IRQHandler  ,
    PCMCD_IRQHandler 
};
