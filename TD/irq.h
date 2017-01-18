#ifndef IRQ_H
#define IRQ_H

#define VTOR (*(volatile uint32_t *) 0xe000ed08) 
#define NVIC_ISER (*(volatile uint32_t *) 0xe000e100) 
#define NVIC_ICER (*(volatile uint32_t *) 0xe000e180) 

#define enable_irq()  do{ asm volatile ("cpsie i"); }while(0)
#define disable_irq() do{ asm volatile ("cpsid i"); }while(0)

#define MAKE_DEFAULT_HANDLER(name)\
    void __attribute__((weak)) name ## _Handler()\
    {\
        disable_irq();\
        while(1);\
    }

#define MAKE_DEFAULT_IRQHANDLER(name)\
    void __attribute__((weak)) name ## _IRQHandler()\
    {\
        disable_irq();\
        while(1);\
    }

void irq_init();
void irq_enable(int);
void irq_disable(int);

#endif
