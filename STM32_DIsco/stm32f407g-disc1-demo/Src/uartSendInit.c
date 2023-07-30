/**
  ******************************************************************************
  * @file    UART/UART_TwoBoards_ComIT/Src/main.c
  * @author  MCD Application Team
  * @brief   This sample code shows how to use STM32F4xx UART HAL API to transmit
  *          and receive a data buffer with a communication process based on
  *          IT transfer.
  *          The communication is done using 2 Boards.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "stm32f4xx_hal_uart.h"
/** @addtogroup STM32F4xx_HAL_Examples
  * @{
  */

/** @addtogroup UART_TwoBoards_ComIT
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TRANSMITTER_BOARD
#define USER_Button

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */
extern UART_HandleTypeDef UartHandle;
__IO ITStatus UartReady = RESET; //multiple definition

/* Buffer used for transmission */
 char aTxBuffer[] = "wsd";

/* Buffer used for reception */
uint8_t aRxBuffer[RXBUFFERSIZE];

/* Private function prototypes -----------------------------------------------*/

//static void Error_Handler(void);
//static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* Turn LED5 on */
  BSP_LED_On(LED5); //red
  while(1)
  {
  }
}
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */



void uartTx(int32_t indx){
	switch ( indx ){
		case 0 :
			strcpy(aTxBuffer,  "w");
			break; /* optional */
		case 1 :
			strcpy(aTxBuffer,"s");
			break; /* optional */
		/* you can have any number of case statements */
		default : /* Optional */
			;
	}



#ifdef TRANSMITTER_BOARD
#ifndef USER_Button
  /* Configure USER Button */
  BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
  /* Wait for USER Button press before starting the Communication */
  while (BSP_PB_GetState(BUTTON_KEY) == RESET)
  {
    /* Toggle LED3 waiting for user to press button */
    BSP_LED_Toggle(LED3);
    HAL_Delay(40);
  }

  /* Wait for USER Button release before starting the Communication */
  while (BSP_PB_GetState(BUTTON_KEY) == SET)
  {
  }
#endif
  /* Turn LED3 off */
  BSP_LED_Off(LED3);

  /* The board sends the message and expects to receive it back */

  /*##-2- Start the transmission process #####################################*/
  /* While the UART in reception process, user can transmit data through
     "aTxBuffer" buffer */
  //if(HAL_UART_Transmit_IT(&UartHandle, (uint8_t*)aTxBuffer, TXBUFFERSIZE)!= HAL_OK)
  if(HAL_UART_Transmit_IT(&UartHandle, (uint8_t*)aTxBuffer, 2)!= HAL_OK)
  {
    Error_Handler();
  }

  /*##-3- Wait for the end of the transfer ###################################*/
  while (UartReady != SET)
  {
  }

//  HAL_Delay(40);

  /* Reset transmission flag */
  UartReady = RESET;

  /*##-4- Put UART peripheral in reception process ###########################*/
  //if(HAL_UART_Receive_IT(&UartHandle, (uint8_t *)aRxBuffer, RXBUFFERSIZE) != HAL_OK)
  if(HAL_UART_Receive_IT(&UartHandle, (uint8_t *)aRxBuffer, 1) != HAL_OK)
  {
    Error_Handler();
  }

#else

  /* The board receives the message and sends it back */

  /*##-2- Put UART peripheral in reception process ###########################*/
  if(HAL_UART_Receive_IT(&UartHandle, (uint8_t *)aRxBuffer, RXBUFFERSIZE) != HAL_OK)
  {
    Error_Handler();
  }

  /*##-3- Wait for the end of the transfer ###################################*/
  while (UartReady != SET)
  {
  }

  /* Reset transmission flag */
  UartReady = RESET;

  /*##-4- Start the transmission process #####################################*/
  /* While the UART in reception process, user can transmit data through
     "aTxBuffer" buffer */
  if(HAL_UART_Transmit_IT(&UartHandle, (uint8_t*)aTxBuffer, TXBUFFERSIZE)!= HAL_OK)
  {
    Error_Handler();
  }

#endif /* TRANSMITTER_BOARD */

  /*##-5- Wait for the end of the transfer ###################################*/
  while (UartReady != SET)
  {
  }

  /* Reset transmission flag */
  UartReady = RESET;
  printf("aTxBuffer,aRxBuffer,RXBUFFERSIZE=%s,%s,%d", aTxBuffer,aRxBuffer,RXBUFFERSIZE);
  /*##-6- Compare the sent and received buffers ##############################*/
/*  if(Buffercmp((uint8_t*)aTxBuffer,(uint8_t*)aRxBuffer,RXBUFFERSIZE))
  {
    Error_Handler();
  }
*/
  /* Infinite loop */
/*  while (1)
  {
  }*/
}

/**
  * @brief  System Clock Configuration
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


/**
  * @brief  Tx Transfer completed callback
  * @param  UartHandle: UART handle.
  * @note   This example shows a simple way to report end of IT Tx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  /* Set transmission flag: transfer complete */
  UartReady = SET;

  /* Turn LED6 on: Transfer in transmission process is correct */
  BSP_LED_On(LED6);
}

/**
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report end of IT Rx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  /* Set transmission flag: transfer complete */
  UartReady = SET;

  /* Turn LED4 on: Transfer in reception process is correct */
  BSP_LED_On(LED4);
}

/**
  * @brief  UART error callbacks
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
 void HAL_UART_ErrorCallback(UART_HandleTypeDef *UartHandle)
{
  /* Turn LED3 on: Transfer error in reception/transmission process */
  BSP_LED_On(LED3);
}
#ifdef COMPARE2BUF
/**
  * @brief  Compares two buffers.
  * @param  pBuffer1, pBuffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval 0  : pBuffer1 identical to pBuffer2
  *         >0 : pBuffer1 differs from pBuffer2
  */
static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if ((*pBuffer1) != *pBuffer2)
    {
      return BufferLength;
    }
    pBuffer1++;
    pBuffer2++;
  }

  return 0;
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
#endif
/**
  * @}
  */

/**
  * @}
  */
