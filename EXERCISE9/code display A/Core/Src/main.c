/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
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
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  // LED MATRIX
      const int MAX_LED_MATRIX = 8;
      int index_led_matrix = 0;
      uint8_t matrix_buffer[8] = { 0xE7, 0xC3, 0x99, 0x99, 0x81, 0x81, 0x99, 0x99 };
      uint8_t matrix_Row[8] = { 0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE };
      	  	  // COL1 COL2 COL3 COL4 COL5 COL6 COL7 COL8
      	  	  // 1    1    1    0    0    1    1    1     0xE7
          	  // 1    1    0    0    0    0    1    1     0xC3
          	  // 1    0    0    1    1    0    1    1     0x99
          	  // 1    0    0    1    1    0    0    1     0x99
          	  // 1    0    0    0    0    0    0    1     0x81
          	  // 1    0    0    0    0    0    0    1     0x81
          	  // 1    0    0    1    1    0    0    1     0x99
          	  // 1    0    0    1    1    0    0    1     0x99
      void setCol (uint8_t valCol ){
    	  HAL_GPIO_WritePin ( ENM0_GPIO_Port, ENM0_Pin, (( valCol >>7 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ENM1_GPIO_Port, ENM1_Pin, (( valCol >>6 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ENM2_GPIO_Port, ENM2_Pin, (( valCol >>5 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ENM3_GPIO_Port, ENM3_Pin, (( valCol >>4 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ENM4_GPIO_Port, ENM4_Pin, (( valCol >>3 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ENM5_GPIO_Port, ENM5_Pin, (( valCol >>2 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ENM6_GPIO_Port, ENM6_Pin, (( valCol >>1 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ENM7_GPIO_Port, ENM7_Pin, (( valCol >>0 ) & 1 )) ;
      }
      	  	  // ROW0 0    1    1    1    1    1    1    1
          	  // ROW1 1    0    1    1    1    1    1    1
          	  // ROW2 1    1    0    1    1    1    1    1
          	  // ROW3 1    1    1    0    1    1    1    1
          	  // ROW4 1    1    1    1    0    1    1    1
          	  // ROW5 1    1    1    1    1    0    1    1
          	  // ROW6 1    1    1    1    1    1    0    1
          	  // ROW7 1    1    1    1    1    1    1    0
              //     0xFF 0xC0 0x80 0x33 0x33 0x80 0xC0 0xFF
      void setRow (uint8_t valRow){
    	  HAL_GPIO_WritePin ( ROW0_GPIO_Port, ROW0_Pin, (( valRow >>7 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ROW1_GPIO_Port, ROW1_Pin, (( valRow >>6 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ROW2_GPIO_Port, ROW2_Pin, (( valRow >>5 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ROW3_GPIO_Port, ROW3_Pin, (( valRow >>4 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ROW4_GPIO_Port, ROW4_Pin, (( valRow >>3 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ROW5_GPIO_Port, ROW5_Pin, (( valRow >>2 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ROW6_GPIO_Port, ROW6_Pin, (( valRow >>1 ) & 1 )) ;
    	  HAL_GPIO_WritePin ( ROW7_GPIO_Port, ROW7_Pin, (( valRow >>0 ) & 1 )) ;
      }
      void setmatrix(){
    	  HAL_GPIO_WritePin ( ROW0_GPIO_Port, ROW0_Pin, SET ) ;
    	  HAL_GPIO_WritePin ( ROW1_GPIO_Port, ROW1_Pin, SET ) ;
    	  HAL_GPIO_WritePin ( ROW2_GPIO_Port, ROW2_Pin, SET ) ;
    	  HAL_GPIO_WritePin ( ROW3_GPIO_Port, ROW3_Pin, SET ) ;
    	  HAL_GPIO_WritePin ( ROW4_GPIO_Port, ROW4_Pin, SET ) ;
    	  HAL_GPIO_WritePin ( ROW5_GPIO_Port, ROW5_Pin, SET ) ;
    	  HAL_GPIO_WritePin ( ROW6_GPIO_Port, ROW6_Pin, SET ) ;
    	  HAL_GPIO_WritePin ( ROW7_GPIO_Port, ROW7_Pin, SET ) ;
      }
      void updateLEDMatrix (int index){
    	  setmatrix();
    	  switch ( index ) {
      	  	  case 0:
      	  		  setCol(matrix_buffer[0]);
      	  		  setRow(matrix_Row[index]);
      	  		  break ;
      	  	  case 1:
      	  		setCol(matrix_buffer[1]);
      	  		setRow(matrix_Row[index]);
      	  		  break ;
      	  	  case 2:
      	  		setCol(matrix_buffer[2]);
      	  		setRow(matrix_Row[index]);
      	  		  break ;
      	  	  case 3:
      	  		setCol(matrix_buffer[3]);
      	  		setRow(matrix_Row[index]);
      	  		  break ;
      	  	  case 4:
      	  		setCol(matrix_buffer[4]);
      	  		setRow(matrix_Row[index]);
      	  		  break ;
      	  	  case 5:
      	  		setCol(matrix_buffer[5]);
      	  		setRow(matrix_Row[index]);
      	  		  break ;
      	  	  case 6:
      	  		setCol(matrix_buffer[6]);
      	  		setRow(matrix_Row[index]);
      	  		  break ;
      	  	  case 7:
      	  		setCol(matrix_buffer[7]);
      	  		setRow(matrix_Row[index]);
      	  		  break ;
      	  	  default :
      	  		  break ;
    	  }
      }
  //  LED 7SEG
      int hour = 15 , minute = 8 , second = 50 ;
        void display7SEG( int num ){
              char LED7SEG [10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
              for ( int i = 0; i < 7; ++ i) {
              HAL_GPIO_WritePin ( GPIOB , GPIO_PIN_0 << i , ( LED7SEG [num ] >> i ) & 1) ;}
              }
        void pinenable(int a){
            	if (a == 0){
            		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
            		HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
            		HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
            		HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
            	}
            	if (a == 1){
            		HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
            		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
            		HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
            		HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
            	}
            	if (a == 2){
            	  	HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
            	  	HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
            	  	HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
            	  	HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
            	  	}
            	if (a == 3){
            	  	HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
            	  	HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
            	  	HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
            	  	HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
            	  	}
            }
        const int MAX_LED = 4;
        int index_led = 0;
        int led_buffer [4] = {1 , 2 , 3 , 4};
        void updateClockBuffer(){
        	led_buffer[0] = hour / 10;
        	led_buffer[1] = hour % 10;
        	led_buffer[2] = minute / 10;
        	led_buffer[3] = minute % 10;
        }
        void update7SEG ( int index ) {
          	switch ( index ) {
          		case 0:
          			// Display the first 7 SEG with led_buffer [0]
          			display7SEG(led_buffer[0]);
          			pinenable(0);
          			break ;
          		case 1:
          			// Display the second 7 SEG with led_buffer [1]
          			display7SEG(led_buffer[1]);
          			pinenable(1);
          			break ;
          		case 2:
          			// Display the third 7 SEG with led_buffer [2]
          			display7SEG(led_buffer[2]);
          			pinenable(2);
          			break ;
          		case 3:
          			// Display the forth 7 SEG with led_buffer [3]
          			display7SEG(led_buffer[3]);
          			pinenable(3);
          	}
        }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setTimer1(1);
  setTimer2(1);
  setTimer3(1);
  setTimer4(1000);
  while (1)
  {
	  // DISPLAY LED MATRIX
	  if(timer1_flag == 1){
	  		  setTimer1(5);
	  		  updateLEDMatrix(index_led_matrix);
	  		  index_led_matrix++;
	  		  if (index_led_matrix >= MAX_LED_MATRIX ) index_led_matrix = 0;
	  }
	  // DISPLAY LED 7SEG
	  if(timer2_flag == 1){
		   	  setTimer2(250);
	  		  update7SEG(index_led);
	  		  index_led++;
	  		  if (index_led >= MAX_LED ) index_led = 0;
	  }
	  // DISPLAY LED_RED & DOT
	  if(timer3_flag == 1){
	  		  setTimer3(500);
	  		  HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	  		  HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
	  		  updateClockBuffer() ;
	  	  	  }
	  // CLOCK
	  	  if(timer4_flag == 1){
	  		  setTimer3(1000);
	  		  second++;
	  		  if ( second >= 60) {
	  			  second = 0;
	  			  minute ++;
	  		  }
	  		  if( minute >= 60) {
	  			  minute = 0;
	  			  hour ++;
	  		  }
	  		  if( hour >=24) {
	  			  hour = 0;
	  		  }
	  	  }
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
  htim2.Init.Prescaler = 799;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|GPIO_PIN_7|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin PB7 ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|GPIO_PIN_7|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timerRun();
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
