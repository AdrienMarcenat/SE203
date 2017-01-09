#ifndef UART_H
#define UART-H

#define SIM_SOPT2  (*(volatile uint32_t *) 0x40048004)
#define SIM_SCGC4   (*(volatile uint32_t *) 0x40048034)
#define UARTO_C4   (*(volatile uint32_t *) 0x4006a00a)
#define UARTO_BDH  (*(volatile uint32_t *) 0x4006a000)
#define UARTO_BDL  (*(volatile uint32_t *) 0x4006a001)

void uart_init();

#endif
