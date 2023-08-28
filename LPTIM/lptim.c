/**
  ******************************************************************************
  * @file    LPTIM.c
	* @author  
	* @Version V1.0.0
  * @Date    2023-8-6
  * @brief   TIM  function
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/

#include "lptim.h"
#include "rjm32l030_conf.h"
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void LPTIM_Task(uint16 count)
{
  LPTIM_TimeBaseInitTypeDef  LPTIM_TimeBaseStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;	
	
  RCC_APBPeriphClockCmd(RCC_APBPeriph_LPTIMER,ENABLE);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_GPIOA | RCC_APB1Periph_GPIOB |  RCC_APB1Periph_GPIOC | RCC_APB1Periph_IOCFG,ENABLE); 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	
  LPTIM_TimeBaseStructure.LPTIM_CLKSRC_SEL = LPTIM_CLKSRC_SEL_LSE;
  LPTIM_TimeBaseStructure.LPTIM_Period = count; 
  LPTIM_TimeBaseStructure.LPTIM_WAKEUP_EN = DISABLE;
  LPTIM_TimeBaseStructure.LPTIM_INT_EN = ENABLE;

  LPTIM_TimeBaseStructure.LPTIM_CT0_EN = ENABLE;
  LPTIM_TimeBaseInit(&LPTIM_TimeBaseStructure);
	
  NVIC_EnableIRQ(LPTIMER_IRQn);
  LPTIM_Cmd(ENABLE); //使能计数
	
}


/*中断回调函数*/
void LPTIM_CallBack_Fun(void)
{
	if(LPTIME_GetFlagStatus(LPTIM_IT_TF0_IE) != RESET)                     // TF0_INT_FLAG
	{
		GPIO_ReversalBits(GPIOA,GPIO_Pin_7);
		LPTIM_ClearITPendingBit(LPTIM_IT_TF0_IE);      
	}	
}


