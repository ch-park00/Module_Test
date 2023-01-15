/*
 * Uart_Printf.h
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */

#ifndef INC_COMP_UART_PRINTF_H_
#define INC_COMP_UART_PRINTF_H_

#include "Comp.h"
#include <stdio.h>

static void MX_USART2_UART_Init(void);
void Uart_Printf_Init();
void Uart_Printf();


#endif /* INC_COMP_UART_PRINTF_H_ */
