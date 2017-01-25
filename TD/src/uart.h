#ifndef UART_H
#define UART_H

void uart_init();
void uart_putchar(char);
unsigned char uart_getchar();

char* frames;

#endif
