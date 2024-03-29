/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "control.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim21;

/* USER CODE BEGIN PV */
uint8_t PA04_flag = 0;
uint8_t HBit,VBit;
unsigned char count = 0;
//uint8_t i;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM21_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM21_Init();
  /* USER CODE BEGIN 2 */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
    //uint32_t pwmValues[] = {0, 5, 10, 15, 20, 25, 30, 35,40,45,50,55,60,65,70,75,80,85,90,95,100,100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 5, 0 };
    //uint32_t PIRVals[] = {5000,0,5000,0,5000,5000,0,5000,0,5000};



    HAL_TIM_PWM_Start(&htim21, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim21, TIM_CHANNEL_2);
    //HAL_TIM_Base_Start_IT(&htim2);
    //TIM2 -> CCR3 = 18;
    //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
/*    TIM21 -> CCR2 = 5000;
    TIM21 -> CCR2 = 0;
    TIM21 -> CCR2 = 5000;
    TIM21 -> CCR2 = 0;
    TIM21 -> CCR2 = 5000;*/
    //HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t *)pwmValues, 40);
    //HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_4, (uint32_t *)PIRVals, 10);
    //HAL_Delay(5000);
   // SetPinB1ToOutput();
   /// HAL_GPIO_WritePin(GPIOA, PIR2_IO_Pin, GPIO_PIN_RESET);
    HAL_Delay(1000);

/*    SetPinB1ToOutput();
    HAL_GPIO_WritePin(GPIOA, PIR2_IO_Pin, GPIO_PIN_RESET);
    HAL_Delay(1000);*/
    //SetPinB1ToInput();
    //setPIR2();
   /* SetPinB1ToOutput();
    HAL_GPIO_WritePin(GPIOA, PIR2_IO_Pin, GPIO_PIN_RESET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(GPIOA, PIR2_IO_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    SetPinB1ToInput();*/


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {               //beginIRScan();
	  	  	  	  TIM21-> CCR1 = 18;
	  		  	  HAL_Delay(500);
	  		  	  TIM21 -> CCR1 = 0;
	  		  	  HAL_Delay(500);
	  		  	  TIM21 -> CCR2 = 18;
	  		  	  HAL_Delay(500);
	  		  	  TIM21 -> CCR2 = 0;
	  		  	  HAL_Delay(500);
	  	 /* TIM21 -> CCR2 = 10;
	  	  //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	  	  HAL_Delay(1000);
	  	  TIM2 -> CCR3 = 0;
	  	  TIM21 -> CCR2 = 0;
	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	  	  HAL_Delay(1000);*/
	/*  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	  HAL_Delay(500);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_Delay(500);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	  HAL_Delay(500);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_Delay(500);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
	  HAL_Delay(500);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	  HAL_Delay(500);*/
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 64000-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM21 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM21_Init(void)
{

  /* USER CODE BEGIN TIM21_Init 0 */

  /* USER CODE END TIM21_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM21_Init 1 */

  /* USER CODE END TIM21_Init 1 */
  htim21.Instance = TIM21;
  htim21.Init.Prescaler = 8-1;
  htim21.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim21.Init.Period = 36-1;
  htim21.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim21.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim21) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim21, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim21) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim21, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim21, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim21, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM21_Init 2 */

  /* USER CODE END TIM21_Init 2 */
  HAL_TIM_MspPostInit(&htim21);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Blue_Pin|Red_Pin|PIR2_SERIAL__Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Green_GPIO_Port, Green_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PROX_VERTICAL_Pin PROX_HORIZONTAL_Pin */
  GPIO_InitStruct.Pin = PROX_VERTICAL_Pin|PROX_HORIZONTAL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Blue_Pin Green_Pin Red_Pin PIR2_SERIAL__Pin */
  GPIO_InitStruct.Pin = Blue_Pin|Green_Pin|Red_Pin|PIR2_SERIAL__Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PIR1_Pin */
  GPIO_InitStruct.Pin = PIR1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PIR1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Button_Pin */
  GPIO_InitStruct.Pin = Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PIR2_IO_Pin */
  GPIO_InitStruct.Pin = PIR2_IO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PIR2_IO_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */


/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void SetPinB1ToOutput(void)
  {
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	  GPIO_InitStruct.Pin = PIR2_IO_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	 // return(0);
  }

void SetPinB1ToInput(void)
  {
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	  GPIO_InitStruct.Pin = PIR2_IO_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  HAL_GPIO_Init(PIR2_IO_GPIO_Port, &GPIO_InitStruct);
  }

/*void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
  {
    //sense2 = 1;
      if(GPIO_Pin == PIR1_Pin)// If The INT Source Is EXTI Line9 (A9 Pin)
      {
    	  HAL_GPIO_TogglePin(GPIOA, Red_Pin); // Toggle The Output (LED) Pin, have it call a timer
      //sense1 = 1;

      }

      else if((PB00_flag & 0x00) ==0x01  ) // If The INT Source Is EXTI Line9 (A9 Pin)
            {
            HAL_GPIO_TogglePin(GPIOA, RED1_Pin); // Toggle The Output (LED) Pin
            sense2 = 1;
            }

      //triggered(sense1,sense2);
  }*/

//// Interrupts

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
  {


      if(GPIO_Pin == PROX_VERTICAL_Pin)// If The INT Source Is EXTI Line9 (A9 Pin)
      {
    	  //HAL_GPIO_TogglePin(GPIOA, Red_Pin); // Toggle The Output (LED) Pin, have it call a timer
    	 // HAL_GPIO_WritePin(GPIOA, Green_Pin, GPIO_PIN_SET);
    	  //HAL_GPIO_WritePin(GPIOA, Red_Pin, GPIO_PIN_RESET);
    	  //HAL_Delay(500);
    	  //HAL_GPIO_WritePin(GPIOA, Green_Pin, GPIO_PIN_RESET);

    	  //RoomEmpty();

    	  VBit = 1;
      }

      if (GPIO_Pin == PROX_HORIZONTAL_Pin)
      {
    	  //HAL_GPIO_WritePin(GPIOA, Red_Pin, GPIO_PIN_SET);
    	  //HAL_GPIO_WritePin(GPIOA, Green_Pin, GPIO_PIN_RESET);

    	  //HAL_GPIO_WritePin(GPIOA, Red_Pin, GPIO_PIN_RESET);
    	  //HAL_GPIO_TogglePin(GPIOA, Green_Pin);
    	//TIM2->CNT = 0;
    	//RoomFull();

    	  HBit = 1;
      }

      if (GPIO_Pin == PIR1_Pin)
            {
          	    //HAL_GPIO_TogglePin(GPIOA, Green_Pin);
          	  //HAL_TIM_Base_Stop_IT(&htim2);
          	  //HAL_TIM_Base_Start_IT(&htim2);
    	        //HAL_GPIO_TogglePin(GPIOA,Red_Pin);

    	  	  	 HAL_GPIO_TogglePin(GPIOA,Red_Pin);
    	  	  	 HAL_TIM_Base_Start_IT(&htim2);

            }
  }


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	//determineOccu();
	HAL_TIM_Base_Stop(&htim2);
	__HAL_TIM_SET_COUNTER(&htim2, 500);

	if (htim->Instance == TIM2) { // Replace TIMx with your timer instance, e.g., TIM2
	        // Clear the timer's interrupt flag to prevent re-entering this ISR due to the same event
	        __HAL_TIM_CLEAR_IT(htim, TIM_IT_UPDATE);

	        // Optionally reset the counter if needed (not always necessary if auto-reload is used)
	        __HAL_TIM_SET_COUNTER(htim, 0);

	        // Here, you can add your code to handle what should happen at each timer interrupt

	        // No explicit restart needed if the timer is configured in auto-reload mode (default for most basic timers)
	    }

//HAL_GPIO_TogglePin(GPIOA, Green_Pin);
/*	  HAL_GPIO_TogglePin(GPIOA,Red_Pin);
	  HAL_GPIO_TogglePin(GPIOA, Green_Pin);*/
	/*count += 1;

	if (count == 2)
	{
		//HAL_TIM_Base_Stop_IT(&htim2);
		count = 0;
	}*/
	//HAL_GPIO_TogglePin(GPIOA, Green_Pin);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
