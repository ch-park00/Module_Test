/*
 * LED.c
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */
#include "LED.h"

void LED_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  GPIO_InitStruct.Pin = LD2_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}

void LED_ON()
{
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
}

void LED_OFF()
{
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}
