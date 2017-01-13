#ifndef UART_H
#define UART_H

int UART_SUM;

void uart_init();
void uart_putchar(char);
unsigned char uart_getchar();
void uart_checksum();
void uart_echo();

#endif
