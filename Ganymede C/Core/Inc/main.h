/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PROX_VERTICAL_Pin GPIO_PIN_14
#define PROX_VERTICAL_GPIO_Port GPIOC
#define PROX_VERTICAL_EXTI_IRQn EXTI4_15_IRQn
#define PROX_HORIZONTAL_Pin GPIO_PIN_15
#define PROX_HORIZONTAL_GPIO_Port GPIOC
#define PROX_HORIZONTAL_EXTI_IRQn EXTI4_15_IRQn
#define Blue_Pin GPIO_PIN_0
#define Blue_GPIO_Port GPIOA
#define Green_Pin GPIO_PIN_1
#define Green_GPIO_Port GPIOA
#define Red_Pin GPIO_PIN_2
#define Red_GPIO_Port GPIOA
#define PIR2_SERIAL__Pin GPIO_PIN_3
#define PIR2_SERIAL__GPIO_Port GPIOA
#define PIR1_Pin GPIO_PIN_4
#define PIR1_GPIO_Port GPIOA
#define PIR1_EXTI_IRQn EXTI4_15_IRQn
#define Button_Pin GPIO_PIN_7
#define Button_GPIO_Port GPIOA
#define Button_EXTI_IRQn EXTI4_15_IRQn
#define PIR2_IO_Pin GPIO_PIN_1
#define PIR2_IO_GPIO_Port GPIOB
#define IR_2_Pin GPIO_PIN_9
#define IR_2_GPIO_Port GPIOA
#define IR_1_Pin GPIO_PIN_10
#define IR_1_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
