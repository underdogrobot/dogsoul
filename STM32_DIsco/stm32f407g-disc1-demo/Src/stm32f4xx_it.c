/*
    Copyright 2020-2021 Picovoice Inc.

    You may not use this file except in compliance with the license. A copy of the license is located in the "LICENSE"
    file accompanying this source.

    Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
    an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
    specific language governing permissions and limitations under the License.
*/
#include "main.h"
#include "stm32f4xx_it.h"

extern I2S_HandleTypeDef       hAudioOutI2s;
extern I2S_HandleTypeDef       hAudioInI2s;
/* Private variables ---------------------------------------------------------*/
/* UART handler declared in "main.c" file */
extern UART_HandleTypeDef UartHandle;
void NMI_Handler(void) {
}

void HardFault_Handler(void) {
  while (1);
}

void MemManage_Handler(void) {
  while (1);
}

void BusFault_Handler(void) {
  while (1);
}

void UsageFault_Handler(void) {
  while (1);
}

void SVC_Handler(void) {
}

void DebugMon_Handler(void) {
}

void PendSV_Handler(void) {
}

void SysTick_Handler(void) {
  HAL_IncTick();
}

void I2S3_IRQHandler(void) {
  HAL_DMA_IRQHandler(hAudioOutI2s.hdmatx);
}

void I2S2_IRQHandler(void) {
  HAL_DMA_IRQHandler(hAudioInI2s.hdmarx);
}
/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) , for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/
/**
  * @brief  This function handles UART interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to DMA stream
  *         used for USART data transmission
  */
void USARTx_IRQHandler(void)
{
  HAL_UART_IRQHandler(& UartHandle);
}



/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

