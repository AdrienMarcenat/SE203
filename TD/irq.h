#ifndef IRQ_H
#define IRQ_H

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

#endif
