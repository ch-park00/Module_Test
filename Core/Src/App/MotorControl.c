/*
 * MotorControl.c
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */
#include "common.h"

#include "MotorControl.h"
#include "MotorDriver.h"
void MotorControl_init()
{
	MotorDriver_Init();
}

// motor 켜져있는지 체크
// 만약 켜져있다면,
// 1초뒤에 정지
/*
void MotorControl_func(MotorControl_flag flag)
{
	if (flag == MotorSys)
	{
		// 만약 모터가 켜져있다면
		if (1)
		{

		}
	}
	else if (flag == MotorOnoff)
	{

	}
}*/
