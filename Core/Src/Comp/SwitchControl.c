/*
 * SwitchControl.c
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */
#include "SwitchControl.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == PushButton_Pin)
	{

	}
}



void Switch_GPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitStruct.Pin = PushButton_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(PushButton_GPIO_Port, &GPIO_InitStruct);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}
