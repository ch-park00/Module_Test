/*
 * Msp.h
 *
 *  Created on: Jan 14, 2023
 *      Author: pch
 */

#ifndef INC_MSP_MSP_H_

#define INC_MSP_MSP_H_
#ifdef __cplusplus

extern "C" {

}
#endif

#include "stm32f1xx_hal.h"
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
#define millis() HAL_GetTick()
void Error_Handler(void);

#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

#define PushButton_Pin GPIO_PIN_13
#define PushButton_GPIO_Port GPIOC
#define PushButton_EXTI_IRQn EXTI15_10_IRQn

#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA

#include <stdbool.h>

#endif /* INC_MSP_MSP_H_ */
