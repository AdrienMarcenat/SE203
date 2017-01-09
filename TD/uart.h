#ifndef UART_H
#define UART_H

#define SIM_SOPT2 (*(volatile uint32_t *) 0x40048004)
#define SIM_SCGC4 (*(volatile uint32_t *) 0x40048034)
#define UARTO_C4  (*(volatile uint8_t *) 0x4006a00a)
#define UARTO_BDH (*(volatile uint8_t *) 0x4006a000)
#define UARTO_BDL (*(volatile uint8_t *) 0x4006a001)
#define UARTO_C1  (*(volatile uint8_t *) 0x4006a002)
#define UARTO_C2  (*(volatile uint8_t *) 0x4006a003)

void uart_init();

#endif
