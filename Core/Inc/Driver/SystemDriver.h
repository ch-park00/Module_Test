/*
 * SystemDriver.h
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */

#ifndef INC_DRIVER_SYSTEMDRIVER_H_
#define INC_DRIVER_SYSTEMDRIVER_H_

#include "LED.h"
#include "SwitchControl.h"
#include "SystemTimer.h"
#include "Uart_Printf.h"

uint16_t Check_SwitchStage();
uint16_t Check_TimerSet();
#endif /* INC_DRIVER_SYSTEMDRIVER_H_ */
