#ifndef __Q_UART_H__
#define __Q_UART_H__


#include <stdint.h>
#include"TM4C123GH6PM.h"
#include "Q_common.h"

void uart0_init(uint32_t baudrate);
void uart0_putc(char c);
void uart0_puts(char* s);




#endif //__Q_UART_H__
