/*
 * SystemControl.h
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */

#ifndef INC_APP_SYSTEMCONTROL_H_
#define INC_APP_SYSTEMCONTROL_H_
#include "App.h"
#include "SystemDriver.h"
#include "common.h"
#define ChatteringTIM 30
#define MotorONOFFTIM 1000
typedef struct
{
	TASK_STATE Tim_1ms;
	TASK_STATE Tim_30ms;
	TASK_STATE Tim_1000ms;
}SYS_CheckTim;
void Check_SystemTimer(TimTask_list *_list, SYS_CheckTim *result);
uint16_t Check_Switch();

#endif /* INC_APP_SYSTEMCONTROL_H_ */
