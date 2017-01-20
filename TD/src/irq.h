#ifndef IRQ_H
#define IRQ_H

#define enable_irq()  do{ asm volatile ("cpsie i"); }while(0)
#define disable_irq() do{ asm volatile ("cpsid i"); }while(0)

void irq_init();
void irq_enable(int);
void irq_disable(int);

#endif
