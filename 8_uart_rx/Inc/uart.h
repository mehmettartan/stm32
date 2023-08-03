/*
 * uart.h
 *
 *  Created on: Apr 18, 2023
 *      Author: ubuntu
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32f4xx.h"

void uart2_tx_init(void);
char uart2_read(void);
void uart2_rxtx_init(void);
void uart2_rx_interrupt_init(void);

#endif /* UART_H_ */
