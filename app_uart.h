#ifndef APP_UART_H
#define	APP_UART_H

#include <xc.h>
#include <stdint.h>

void printf(uint8_t string[30], uint8_t new_line);
void printf_num(uint16_t dado);

#endif	

