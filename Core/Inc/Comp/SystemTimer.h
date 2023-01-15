/*
 * SystemTimer.h
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */

#ifndef INC_COMP_SYSTEMTIMER_H_
#define INC_COMP_SYSTEMTIMER_H_

#include "Comp.h"
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void SystemTimer_Init();
uint16_t Check_TimerIRQFlag();
static void MX_TIM1_Init(void);
/*
typedef enum
{
	FLAG_SET,
	FLAG_RESET
}TIM_FLAG;
*/
#endif /* INC_COMP_SYSTEMTIMER_H_ */
