/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @file    TIM/TIM_TimeBase/Src/main.c
 * @brief          : Main program body
 *
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
#include "LIS3DSH.h"
#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#include "stm32f4_discovery.h"
#include "pv_picovoice.h"
#include "pv_audio_rec.h"
#include "pv_params.h"
#include "pv_st_f407.h"

#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_hal_spi.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
TIM_HandleTypeDef TimHandle;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MEMORY_BUFFER_SIZE (70 * 1024)


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
int8_t READ_ACC = 0;
static const float PORCUPINE_SENSITIVITY = 0.75f;
static const float RHINO_SENSITIVITY = 0.5f;
static const float RHINO_ENDPOINT_DURATION_SEC = 1.0f;
static const bool RHINO_REQUIRE_ENDPOINT = true;

static const char* ACCESS_KEY = "fKXqfXSOn2RG3z0SQmfIBe5Oe9eU9B0EtDhxNhaNNUrdCPVERLIkAQ=="; //AccessKey string obtained from Picovoice Console (https://picovoice.ai/console/)
/* UART handler declaration */
UART_HandleTypeDef UartHandle;
//__IO ITStatus UartReady = RESET;
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
TIM_HandleTypeDef TimHandle;
static int8_t memory_buffer[MEMORY_BUFFER_SIZE] __attribute__((aligned(16)));
uint32_t uwPrescalerValue = 0;
uint8_t WALK=0, STAND=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void accConfigInit(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_TIM1_Init(void);
static void my_TIM3_Init(void);
/* USER CODE BEGIN PFP */
void readACC(void);
static void SystemClock_Config(void);
//static void error_handler(void);
//static void error_handler(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
//static void error_handler(void)
int error_handler(void)
{
	/* USER CODE BEGIN error_handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END error_handler_Debug */
}
/* USER CODE END 0 */

void accConfigInit(void){
	LIS3DSH_InitTypeDef accConfigDef;

	accConfigDef.dataRate = LIS3DSH_DATARATE_3_125; /* 3.125 Hz Normal Mode */
	accConfigDef.fullScale = LIS3DSH_FULLSCALE_16;   /* 16 g  */
	accConfigDef.enableAxes = LIS3DSH_XYZ_ENABLE;
	accConfigDef.antiAliasingBW = LIS3DSH_FILTER_BW_50;  /* 50 Hz  */
	accConfigDef.interruptEnable = false;

	LIS3DSH_Init(&hspi1, &accConfigDef);
}

void readACC(void)
{
	/* USER CODE BEGIN 1 */
	const uint8_t UART_BUF_MAX = 80;
	uint8_t buf[UART_BUF_MAX];
	HAL_StatusTypeDef ret;
	//LIS3DSH_InitTypeDef accConfigDef;
	LIS3DSH_DataScaled acc;
	/* USER CODE END 1 */

	/* USER CODE BEGIN 3 */
	if(LIS3DSH_PollDRDY(1000))
	{
		acc = LIS3DSH_GetDataScaled();
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);

		sprintf((char*)buf,"#AccXYZ:%.12f,%.12f,%.12f\r\n", acc.x, acc.y, acc.z);
		printf("#XYZ:%.12f,%.12f,%.12f\r\n", acc.x, acc.y, acc.z);
		//printf("#AccXYZ:%5.2f,%5.2f,%5.2f\r\n", acc.x, acc.y, acc.z);
		ret = HAL_UART_Transmit(&huart3, buf, strlen((char*)buf), HAL_MAX_DELAY);
		if(ret != HAL_OK) {
			strcpy((char*)buf, "Error Tx:%d\r\n");
		}

	}
}

/**
 * @brief SPI1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_SPI1_Init(void)
{

	/* USER CODE BEGIN SPI1_Init 0 */

	/* USER CODE END SPI1_Init 0 */

	/* USER CODE BEGIN SPI1_Init 1 */

	/* USER CODE END SPI1_Init 1 */
	/* SPI1 parameter configuration*/
	hspi1.Instance = SPI1;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_SOFT;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi1) != HAL_OK)
	{
		error_handler();
	}
	/* USER CODE BEGIN SPI1_Init 2 */

	/* USER CODE END SPI1_Init 2 */

}

/**
 * @brief TIM1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM1_Init(void)
{

	/* USER CODE BEGIN TIM1_Init 0 */

	/* USER CODE END TIM1_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_SlaveConfigTypeDef sSlaveConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM1_Init 1 */

	/* USER CODE END TIM1_Init 1 */
	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 0;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 65535;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.RepetitionCounter = 0;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
	{
		error_handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
	{
		error_handler();
	}
	sSlaveConfig.SlaveMode = TIM_SLAVEMODE_RESET;
	sSlaveConfig.InputTrigger = TIM_TS_ETRF;
	sSlaveConfig.TriggerPolarity = TIM_TRIGGERPOLARITY_NONINVERTED;
	sSlaveConfig.TriggerPrescaler = TIM_TRIGGERPRESCALER_DIV1;
	sSlaveConfig.TriggerFilter = 0;
	if (HAL_TIM_SlaveConfigSynchro(&htim1, &sSlaveConfig) != HAL_OK)
	{
		error_handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
	{
		error_handler();
	}
	/* USER CODE BEGIN TIM1_Init 2 */

	/* USER CODE END TIM1_Init 2 */

}


/* USER CODE BEGIN TIM3_Init 2 */
/*##-1- Configure the TIM peripheral #######################################*/
/* -----------------------------------------------------------------------
  In this example TIM3 input clock (TIM3CLK) is set to 2 * APB1 clock (PCLK1),
  since APB1 prescaler is different from 1.
    TIM3CLK = 2 * PCLK1
    PCLK1 = HCLK / 4
    => TIM3CLK = HCLK / 2 = SystemCoreClock /2
  To get TIM3 counter clock at 10 KHz, the Prescaler is computed as following:
  Prescaler = (TIM3CLK / TIM3 counter clock) - 1
  Prescaler = ((SystemCoreClock /2) /10 KHz) - 1

  Note:
   SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
   Each time the core clock (HCLK) changes, user had to update SystemCoreClock
   variable value. Otherwise, any configuration based on this variable will be incorrect.
   This variable is updated in three ways:
    1) by calling CMSIS function SystemCoreClockUpdate()
    2) by calling HAL API function HAL_RCC_GetSysClockFreq()
    3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
----------------------------------------------------------------------- */
static void my_TIM3_Init(void)
{
	/* Compute the prescaler value to have TIM3 counter clock equal to 10 KHz */
	uwPrescalerValue = (uint32_t) ((SystemCoreClock /2) / 10000) - 1;

	/* Set TIMx instance */
	TimHandle.Instance = TIMx;

	/* Initialize TIM3 peripheral as follow:
		 + Period = 10000 - 1
		 + Prescaler = ((SystemCoreClock/2)/10000) - 1
		 + ClockDivision = 0
		 + Counter direction = Up
	 */
	TimHandle.Init.Period = 10000 - 1;
	TimHandle.Init.Prescaler = uwPrescalerValue;
	TimHandle.Init.ClockDivision = 0;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if(HAL_TIM_Base_Init(&TimHandle) != HAL_OK)
	{
		/* Initialization Error */
		error_handler();
	}


}
/* USER CODE END TIM3_Init 2 */

/* USER CODE BEGIN TIM3_Init 3 */
/**
 * @brief  Period elapsed callback in non blocking mode
 * @param  htim: TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	READ_ACC = 1;	// true,  a FLAG to read accelerometer
	BSP_LED_Toggle(LED4);  //
}
/* USER CODE END TIM3_Init  */
/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void)
{

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		error_handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/**
 * @brief USART3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART3_UART_Init(void)
{

	/* USER CODE BEGIN USART3_Init 0 */

	/* USER CODE END USART3_Init 0 */

	/* USER CODE BEGIN USART3_Init 1 */

	/* USER CODE END USART3_Init 1 */
	huart3.Instance = USART3;
	huart3.Init.BaudRate = 115200;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart3) != HAL_OK)
	{
		error_handler();
	}
	/* USER CODE BEGIN USART3_Init 2 */

	/* USER CODE END USART3_Init 2 */

}
static void my_UART2_Init()
{
	/*##-1- Configure the UART peripheral ######################################*/
	/* Put the USART peripheral in the Asynchronous mode (UART Mode) */
	/* UART1 configured as follow:
      - Word Length = 8 Bits
      - Stop Bit = One Stop bit
      - Parity = None
      - BaudRate = 9600 baud
      - Hardware flow control disabled (RTS and CTS signals) */
	UartHandle.Instance          = USARTx;

	UartHandle.Init.BaudRate     = 9600;
	UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits     = UART_STOPBITS_1;
	UartHandle.Init.Parity       = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode         = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;

	if(HAL_UART_Init(&UartHandle) != HAL_OK)
	{
		error_handler();
	}
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
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(MEMS_CS_GPIO_Output_GPIO_Port, MEMS_CS_GPIO_Output_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD, LED_Green_Pin|LED_Orange_Pin|LED_Red_Pin|LED_Blue_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : MEMS_CS_GPIO_Output_Pin */
	GPIO_InitStruct.Pin = MEMS_CS_GPIO_Output_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(MEMS_CS_GPIO_Output_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : LED_Green_Pin LED_Orange_Pin LED_Red_Pin LED_Blue_Pin */
	GPIO_InitStruct.Pin = LED_Green_Pin|LED_Orange_Pin|LED_Red_Pin|LED_Blue_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pin : PE0 */
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */



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
/* @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 168000000
 *            HCLK(Hz)                       = 168000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 8000000
 *            PLL_M                          = 8
 *            PLL_N                          = 336
 *            PLL_P                          = 2
 *            PLL_Q                          = 7
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable Power Control clock */
	__HAL_RCC_PWR_CLK_ENABLE();

	/* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

	/* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
	if (HAL_GetREVID() == 0x1001)
	{
		/* Enable the Flash prefetch */
		__HAL_FLASH_PREFETCH_BUFFER_ENABLE();
	}
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif
/* USER CODE BEGIN 4 */

extern void uartSendInit(void);
extern void uartTx(int32_t indx);
/* USER CODE END 4 */
static void wake_word_callback(void) {
	printf("[wake word]\n");
	BSP_LED_On(LED4);
}


static void inference_callback(pv_inference_t *inference) {
	BSP_LED_Off(LED4);
	printf("{\n");
	printf("    is_understood : '%s',\n", (inference->is_understood ? "true" : "false"));
	if (inference->is_understood) {
		printf("    intent : '%s',\n", inference->intent);
		if (inference->num_slots > 0) {
			printf("    slots : {\n");
			for (int32_t i = 0; i < inference->num_slots; i++) {
				printf("        '%s' : '%s',\n", inference->slots[i], inference->values[i]);
				if(strcmp(inference->values[i], "penthouse")==0){
					//uartTx(inference->num_slots);
					WALK = 1;
					STAND =0;
				}else if (strcmp(inference->values[i], "p one") == 0){
					//Xmit after pv_inference_delete
					STAND = 1;
					WALK = 0;
				}
			}
			printf("    }\n");
		}
	}
	printf("}\n\n");
	for (int32_t i = 0; i < 10; i++) {
		BSP_LED_Toggle(LED3);
		BSP_LED_Toggle(LED4);
		BSP_LED_Toggle(LED5);
		BSP_LED_Toggle(LED6);
		HAL_Delay(30);
	}
	pv_inference_delete(inference);
	if (WALK)
		uartTx(0);
	else if (STAND)
		uartTx(1);
}

int main(void) {
	/* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
	 */
	HAL_Init();
	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_SPI1_Init();
	MX_USART1_UART_Init();
	MX_USART3_UART_Init();
	MX_TIM1_Init();

	my_TIM3_Init();
	my_UART2_Init();

	/* Configure LED3, LED4, LED5 and LED6 */
	BSP_LED_Init(LED3);
	BSP_LED_Init(LED4);
	BSP_LED_Init(LED5);
	BSP_LED_Init(LED6);

	/* Configure the system clock to 168 MHz */
	SystemClock_Config();
	/* USER CODE BEGIN 3 */
	accConfigInit();


	/* USER CODE BEGIN 3 */
	//uartSendInit();
	pv_status_t status = pv_board_init();
	if (status != PV_STATUS_SUCCESS) {
		error_handler();
	}
	const uint8_t *board_uuid = pv_get_uuid();
	printf("UUID: ");
	for (uint32_t i = 0; i < pv_get_uuid_size(); i++) {
		printf(" %.2x", board_uuid[i]);
	}
	printf("\r\n");
	status = pv_audio_rec_init();
	if (status != PV_STATUS_SUCCESS) {
		printf("Audio init failed with '%s'", pv_status_to_string(status));
		error_handler();
	}
	status = pv_audio_rec_start();
	if (status != PV_STATUS_SUCCESS) {
		printf("Recording audio failed with '%s'", pv_status_to_string(status));
		error_handler();
	}
	pv_picovoice_t *handle = NULL;
	status = pv_picovoice_init(
			ACCESS_KEY,
			MEMORY_BUFFER_SIZE,
			memory_buffer,
			sizeof(KEYWORD_ARRAY),
			KEYWORD_ARRAY,
			PORCUPINE_SENSITIVITY,
			wake_word_callback,
			sizeof(CONTEXT_ARRAY),
			CONTEXT_ARRAY,
			RHINO_SENSITIVITY,
			RHINO_ENDPOINT_DURATION_SEC,
			RHINO_REQUIRE_ENDPOINT,
			inference_callback,
			&handle);
	if (status != PV_STATUS_SUCCESS) {
		printf("Picovoice init failed with '%s'", pv_status_to_string(status));
		error_handler();
	}
	const char *rhino_context = NULL;
	status = pv_picovoice_context_info(handle, &rhino_context);
	if (status != PV_STATUS_SUCCESS) {
		printf("retrieving context info failed with '%s'", pv_status_to_string(status));
		error_handler();
	}
	printf("Rhino context info: %s\r\n", rhino_context);
	printf("hello hello hello");
	/* USER CODE BEGIN 3 */
	/*##-2- Start the TIM Base generation in interrupt mode ####################*/
	/* Start Channel1 */
	if(HAL_TIM_Base_Start_IT(&TimHandle) != HAL_OK)
	{
		/* Starting Error */
		error_handler();
	}
	/* USER CODE BEGIN 3 */
	while (true) {
		const int16_t *buffer = pv_audio_rec_get_new_buffer();
		if (buffer) {
			const pv_status_t status = pv_picovoice_process(handle, buffer);
			if (status != PV_STATUS_SUCCESS) {
				printf("Picovoice process failed with '%s'", pv_status_to_string(status));
				error_handler();
			}
		}

#ifndef READacc
		if (READ_ACC ) {
			readACC();
			READ_ACC = 0; // reset to false
		}
#endif
	}
	pv_board_deinit();
	pv_audio_rec_deinit();
	pv_picovoice_delete(handle);
}


/**
 * @brief System Clock Configuration
 * @retval None
 */

/**
 * @}
 */

/**
 * @}
 */
