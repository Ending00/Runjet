/**
  ******************************************************************************
  * @file    rjm32l030_lptim.c
  * @author  Runjet Application Team
  * @version V0.0.0
  * @date    23-August-2023
  * @brief   This file provides all the TIM firmware functions.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2023 Runjet</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rjm32l030_lptim.h"

/**
  * @brief  Initializes the LPTIM Time Base Unit peripheral according to 
  *         the specified parameters in the TIM_TimeBaseInitStruct.
  * @param  LPTIM_TimeBaseInitStruct: pointer to a TIM_TimeBaseInitTypeDef
  *         structure that contains the configuration information for the 
  *         specified TIM peripheral.
  * @retval None
  */

void LPTIM_TimeBaseInit(LPTIM_TimeBaseInitTypeDef* LPTIM_TimeBaseInitStruct)
{ 
    /* Check the parameters */
    assert_param(IS_LPTIM_CLKSRC_SEL(LPTIM_TimeBaseStructure.LPTIM_CLKSRC_SEL));  
	
    if(LPTIM_TimeBaseInitStruct->LPTIM_CLKSRC_SEL & LPTIM_CLKSRC_SEL_LSE)
    {
      CRG->SCSYS |= 0x1400;
      CRG->CKEN_CTRL1 |= 0x40000;
    }
    LPTIM->LPTIM_T0CON	|= (LPTIM_TimeBaseInitStruct->LPTIM_WAKEUP_EN<<8);
    LPTIM->LPTIM_T0CON	|= LPTIM_TimeBaseInitStruct->LPTIM_INT_EN;
    LPTIM->LPTIM_TL0 = LPTIM_TimeBaseInitStruct->LPTIM_Period;
    LPTIM->LPTIM_T0MOD |= LPTIM_TimeBaseInitStruct->LPTIM_CT0_EN;
}

/**
  * @brief  Enables or disables the specified LPTIM peripheral.
  * @param  NewState: new state of the TIMx peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void LPTIM_Cmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the LPTIM Counter */
    LPTIM->LPTIM_EN |= 0x0001;
  }
  else
  {
    /* Disable the LPTIM Counter */
    LPTIM->LPTIM_EN &= (uint16_t)(~((uint16_t)0x0001));
  }
}

/**
  * @brief  Checks whether the TIM interrupt has occurred or not.
  * @param  TIM_IT: specifies the TIM interrupt source to check.
  * @note
  * @retval The new state of the TIM_IT(SET or RESET).
  */
ITStatus LPTIME_GetFlagStatus(uint8_t TIM_IT)
{
  FlagStatus flagStatus;

  if(LPTIM->LPTIM_T0CON & (TIM_IT))
  {
    flagStatus = SET;
  }
  else
  {
    flagStatus = RESET;
  }
  return flagStatus;
}

/**
  * @brief  Clears the TIMx's interrupt pending bits.
  * @param  TIM_IT: specifies the pending bit to clear.  
  * @retval None
  */
void LPTIM_ClearITPendingBit(uint8_t TIM_IT)
{
  /* Clear the IT pending Bit */
  LPTIM->LPTIM_T0CON |= (uint8_t)TIM_IT;
}


