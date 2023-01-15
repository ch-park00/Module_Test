/*
 * SystemDriver.c
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */


#include "SystemDriver.h"
void SystemDrivier_init()
{
	SystemTimer_Init();
	Uart_Printf_Init();
	LED_Init();
	Switch_GPIO_Init();
}
/*
uint16_t Check_TimerSet()
{
	return Check_TimerIRQFlag();
}*/
