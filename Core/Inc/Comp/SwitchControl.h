/*
 * SwitchControl.h
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */

#ifndef INC_COMP_SWITCHCONTROL_H_
#define INC_COMP_SWITCHCONTROL_H_

#include "Comp.h"
#define Switch_Val	HAL_GPIO_ReadPin(PushButton_GPIO_Port, PushButton_Pin)

void Switch_GPIO_Init();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);


#endif /* INC_COMP_SWITCHCONTROL_H_ */
