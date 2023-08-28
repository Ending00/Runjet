/**
  ******************************************************************************
  * @file    rjm32l030_tim.c
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
#include "rjm32l030_tim.h"

/**
  * @brief  Configure the TI0 as CAP Input.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  TIM_ICPolarity : The Input Polarity.
  * @param  TIM_ICSelection: specifies the input to be used.
  * @param  TIM_ICFilter: Specifies the Input Capture Filter.
  *   This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
static void TI0_Config(TIMER_Type* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,
                       uint16_t TIM_ICFilter)
{
  uint32_t tmpccmr1 = 0, tmpccer = 0;
  TIMx->TIM_CCCR &= (uint32_t)~((uint32_t)TIM_CAP_CC0E); 
  tmpccer = TIMx->TIM_CCCR;
  tmpccmr1 = TIMx->TIM_ICMR;
  if((TIMx == TIMER0) || (TIMx == TIMER1)|| (TIMx == TIMER2) || (TIMx == TIMER3)||(TIMx == TIMER4)) 
  {
    tmpccer |= TIM_CAP_CC0E;
    tmpccmr1 |= (uint32_t)((TIM_ICPolarity<< (uint32_t)2) | (uint32_t)(TIM_ICSelection << (uint32_t)0)| (uint32_t)(TIM_ICFilter << (uint32_t)4));  
  }  
  
  TIMx->TIM_ICMR = tmpccmr1;
  TIMx->TIM_CCCR = tmpccer;
}

/**
  * @brief  Configure the TI1 as CAP Input.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  TIM_ICPolarity : The Input Polarity.
  * @param  TIM_ICSelection: specifies the input to be used.
  * @param  TIM_ICFilter: Specifies the Input Capture Filter.
  *   This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
static void TI1_Config(TIMER_Type* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,
                       uint16_t TIM_ICFilter)
{
  uint32_t tmpccmr1 = 0, tmpccer = 0;
  TIMx->TIM_CCCR &= (uint32_t)~((uint32_t)TIM_CAP_CC1E); 
  tmpccer = TIMx->TIM_CCCR;
  tmpccmr1 = TIMx->TIM_ICMR;
  if((TIMx == TIMER3)||(TIMx == TIMER4))
  {
    tmpccer |= TIM_CAP_CC1E;
    tmpccmr1 |= (uint32_t)((TIM_ICPolarity<< (uint32_t)10) | (uint32_t)(TIM_ICSelection << (uint32_t)8)| (uint32_t)(TIM_ICFilter << (uint32_t)12));  
  }  
  
  TIMx->TIM_ICMR = tmpccmr1;
  TIMx->TIM_CCCR = tmpccer;
}

/**
  * @brief  Configure the TI2 as CAP Input.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  TIM_ICPolarity : The Input Polarity.
  * @param  TIM_ICSelection: specifies the input to be used.
  * @param  TIM_ICFilter: Specifies the Input Capture Filter.
  *   This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
static void TI2_Config(TIMER_Type* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,
                       uint16_t TIM_ICFilter)
{
  uint32_t tmpccmr1 = 0, tmpccer = 0;
  TIMx->TIM_CCCR &= (uint32_t)~((uint32_t)TIM_CAP_CC2E); 
  tmpccer = TIMx->TIM_CCCR;
  tmpccmr1 = TIMx->TIM_ICMR;
  if((TIMx == TIMER3)||(TIMx == TIMER4))
  {
    tmpccer |= TIM_CAP_CC2E;
    tmpccmr1 |= (uint32_t)((TIM_ICPolarity<< (uint32_t)18) | (uint32_t)(TIM_ICSelection << (uint32_t)16)| (uint32_t)(TIM_ICFilter << (uint32_t)20));  
  }  
  
  TIMx->TIM_ICMR = tmpccmr1;
  TIMx->TIM_CCCR = tmpccer;
}

/**
  * @brief  Configure the TI3 as CAP Input.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  TIM_ICPolarity : The Input Polarity.
  * @param  TIM_ICSelection: specifies the input to be used.
  * @param  TIM_ICFilter: Specifies the Input Capture Filter.
  *   This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
static void TI3_Config(TIMER_Type* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,
                       uint16_t TIM_ICFilter)
{
  uint32_t tmpccmr1 = 0, tmpccer = 0;
  TIMx->TIM_CCCR &= (uint32_t)~((uint32_t)TIM_CAP_CC3E); 
  tmpccer = TIMx->TIM_CCCR;
  tmpccmr1 = TIMx->TIM_ICMR;
  if((TIMx == TIMER3)||(TIMx == TIMER4))
  {
    tmpccer |= TIM_CAP_CC3E;
    tmpccmr1 |= (uint32_t)((TIM_ICPolarity<< (uint32_t)26) | (uint32_t)(TIM_ICSelection << (uint32_t)24)| (uint32_t)(TIM_ICFilter << (uint32_t)28));  
  }  
  
  TIMx->TIM_ICMR = tmpccmr1;
  TIMx->TIM_CCCR = tmpccer;
}

/**
  * @brief  Initializes the TIM peripheral according to the specified
  *         parameters in the TIM_ICInitStruct.
  * @param  TIMx: where x can be  0 to 4 to select the TIM peripheral.
  * @param  TIM_ICInitStruct: pointer to a TIM_ICInitTypeDef structure
  *         that contains the configuration information for the specified TIM peripheral.
  * @retval None
  */
void TIM_ICInit(TIMER_Type* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct)
{
  /* Check the parameters */
  assert_param(IS_TIM_CHANNEL(TIM_ICInitStruct->TIM_Channel)); 
  assert_param(IS_TIM_IC_SELECTION(TIM_ICInitStruct->TIM_ICSelection));
  assert_param(IS_TIM_IC_PRESCALER(TIM_ICInitStruct->TIM_ICFilterCP));
  assert_param(IS_TIM_IC_POLARITY_LITE(TIM_ICInitStruct->TIM_ICPolarity));

  if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_0)
  {
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    /* TI0 Configuration */
    TI0_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
               TIM_ICInitStruct->TIM_ICSelection,
               TIM_ICInitStruct->TIM_ICFilterCP);
  }  
  if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_1)
  {
    assert_param(IS_TIM_34_PERIPH(TIMx));
    /* TI0 Configuration */
    TI1_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
               TIM_ICInitStruct->TIM_ICSelection,
               TIM_ICInitStruct->TIM_ICFilterCP);
  }  
  if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_2)
  {
    assert_param(IS_TIM_34_PERIPH(TIMx));
    /* TI0 Configuration */
    TI2_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
               TIM_ICInitStruct->TIM_ICSelection,
               TIM_ICInitStruct->TIM_ICFilterCP);
  }  
  if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_3)
  {
    assert_param(IS_TIM_34_PERIPH(TIMx));
    /* TI0 Configuration */
    TI3_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
               TIM_ICInitStruct->TIM_ICSelection,
               TIM_ICInitStruct->TIM_ICFilterCP);
  } 
}

/**
  * @brief  Configures the: Break feature, dead time, the OSSI,
  *         the OSSR State and the AOE(automatic output enable).
  * @param  TIMx: where x can be  3 or 4 to select the TIM 
  * @param  TIM_BDTRInitStruct: pointer to a TIM_BDTRInitTypeDef structure that
  *         contains the BDTR Register configuration  information for the TIM peripheral.
  * @retval None
  */
void TIM_BDTRConfig(TIMER_Type* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct)
{
  uint32_t tmpccer = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_AUTO_OUTPUT_STATE(TIM_BDTRInitStruct->TIM_AutoOutput));
  assert_param(IS_TIM_BREAK_POLARITY(TIM_BDTRInitStruct->TIM_BreakPolarity));
  assert_param(IS_TIM_BREAK_STATE(TIM_BDTRInitStruct->TIM_Break)); 
  assert_param(IS_TIM_OSSR_STATE(TIM_BDTRInitStruct->TIM_OSSRState));
  assert_param(IS_TIM_OSSI_STATE(TIM_BDTRInitStruct->TIM_OSSIState));
  assert_param(IS_TIM_EXTBREAK_STATE(TIM_BDTRInitStruct->TIM_ExtBreak));
  assert_param(IS_TIM_COMPBREAK_STATE(TIM_BDTRInitStruct->TIM_CompBreak));
  assert_param(IS_TIM_COMPBREAK_SEL(TIM_BDTRInitStruct->TIM_CompBreakSel)); 

  tmpccer = TIMx->TIM_BDTR;
  if((TIMx == TIMER3)||(TIMx == TIMER4))
  {
    tmpccer  |=  ((TIM_BDTRInitStruct->TIM_AutoOutput))   | \
                 ((TIM_BDTRInitStruct->TIM_BreakPolarity))| \
                 ((TIM_BDTRInitStruct->TIM_Break))        | \
                 ((TIM_BDTRInitStruct->TIM_OSSRState))    | \
                 ((TIM_BDTRInitStruct->TIM_OSSIState))    | \
                 ((TIM_BDTRInitStruct->TIM_BreakFilter)<<4)  | \
                 ((TIM_BDTRInitStruct->TIM_ExtBreak))     | \
                 ((TIM_BDTRInitStruct->TIM_CompBreak))    | \
                 ((TIM_BDTRInitStruct->TIM_CompBreakSel));
  }  
  TIMx->TIM_BDTR = tmpccer;
}

/**
  * @brief  Clears the TIMx's Break flags.
  * @param  TIMx: where x can be 3 to 4 to select the TIM peripheral.
  * @retval None
  */
void TIM_ClearBreakFlag(TIMER_Type* TIMx)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  /* Clear the IT pending Bit */
  TIMx->TIM_ISR &= (uint32_t)TIM_IT_BK_MARK;
}

/**
  * @brief  Clears the TIMx's interrupt pending bits.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  TIM_IT: specifies the pending bit to clear.  
  * @retval None
  */
void TIM_ClearITPendingBit(TIMER_Type* TIMx, uint32_t TIM_IT)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_IT(TIM_IT));
  /* Clear the IT pending Bit */
  TIMx->TIM_ISR &= (uint32_t)TIM_IT;
}

/**
  * @brief  Enables or disables the specified TIM peripheral.
  * @param  TIMx: where x can be 1 to 17 to select the TIMx peripheral.
  * @param  NewState: new state of the TIMx peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM_Cmd(TIMER_Type* TIMx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the TIM Counter */
    TIMx->TIM_CR2 |= 0x0001;
  }
  else
  {
    /* Disable the TIM Counter */
    TIMx->TIM_CR2 &= (uint16_t)(~((uint16_t)0x0001));
  }
}

/**
  * @brief  Specifies the TIMx Counter Mode to be used.
  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
  * @param  TIM_CounterMode: specifies the Counter Mode to be used
  *   This parameter can be one of the following values:
  *     @arg TIM_CounterMode_Up: TIM Up Counting Mode
  *     @arg TIM_CounterMode_Down: TIM Down Counting Mode
  *     @arg TIM_CounterMode_CenterAligned1: TIM Center Aligned Mode1
  *     @arg TIM_CounterMode_CenterAligned2: TIM Center Aligned Mode2
  *     @arg TIM_CounterMode_CenterAligned3: TIM Center Aligned Mode3
  * @retval None
  */
void TIM_CounterModeConfig(TIMER_Type* TIMx, uint16_t TIM_CounterMode)
{
  uint32_t tmpcr1 = 0;
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_COUNTER_MODE(TIM_CounterMode));
  tmpcr1 = TIMx->TIM_CR1;
  /* Reset the CMS and DIR Bits */
  tmpcr1 &= (uint16_t)(~((uint16_t)(TIM_CR1_DIR)));
  /* Set the Counter Mode */
  tmpcr1 |= TIM_CounterMode;
  /* Write to TIMx CR1 register */
  TIMx->TIM_CR1 = tmpcr1;
}

/**
  * @brief  Enables or disables the TIM peripheral Main Outputs.
  * @param  TIMx: where x can be 0 to 4 to select the TIMx peripheral.
  * @param  NewState: new state of the TIM peripheral Main Outputs.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM_CtrlPWMOutputs(TIMER_Type* TIMx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* Enable the TIM Main Output */
    TIMx->TIM_BDTR |= TIM_BDTR_MOE;
  }
  else
  {
    /* Disable the TIM Main Output */
    TIMx->TIM_BDTR &= (uint16_t)(~((uint16_t)TIM_BDTR_MOE));
  }  
}

/**
  * @brief  Enables or disables the TIMx's DMA Requests.
  * @param  TIMx: where x can be 3, 4
  *   to select the TIM peripheral. 
  * @param  TIM_DMASource: specifies the DMA Request sources.
  *   This parameter can be any combination of the following values:
  *     @arg TIM_DMA_Update: TIM update Interrupt source
  *     @arg TIM_DMA_CC0: TIM Capture Compare 0 DMA source
  *     @arg TIM_DMA_CC1: TIM Capture Compare 1 DMA source
  *     @arg TIM_DMA_CC2: TIM Capture Compare 2 DMA source
  *     @arg TIM_DMA_CC3: TIM Capture Compare 3 DMA source
  *     @arg TIM_DMA_Trigger: TIM Trigger DMA source
  * @param  NewState: new state of the DMA Request sources.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM_DMACmd(TIMER_Type* TIMx, uint32_t TIM_DMASource, FunctionalState NewState)
{ 
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the DMA sources */
    TIMx->TIM_DIER |= TIM_DMASource; 
  }
  else
  {
    /* Disable the DMA sources */
    TIMx->TIM_DIER &= (uint32_t)~TIM_DMASource;
  }
}

/**
  * @brief  Configures the External clock Mode1
  * @param  TIMx: where x can be  3, 4 to select the TIM peripheral.
  * @param  TIM_ExtTRGPrescaler: The external Trigger Prescaler.
  * @param  TIM_ExtTRGPolarity: The external Trigger Polarity.
  * @param  ExtTRGFilter: External Trigger Filter.
  *   This parameter must be a value between 0x00 and 0x0F
  * @retval None
  */
void TIM_ETRClockMode1Config(TIMER_Type* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                             uint16_t ExtTRGFilter)
{
  uint16_t tmpsmcr = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_EXT_PRESCALER(TIM_ExtTRGPrescaler));
  assert_param(IS_TIM_EXT_POLARITY(TIM_ExtTRGPolarity));
  assert_param(IS_TIM_EXT_FILTER(ExtTRGFilter));
  /* Configure the ETR Clock source */
  TIM_ETRConfig(TIMx, TIM_ExtTRGPrescaler, TIM_ExtTRGPolarity, ExtTRGFilter);
  
  /* Get the TIMx SMCR register value */
  tmpsmcr = TIMx->TIM_SMCR;
  /* Enable the External clock mode1 */
  TIMx->TIM_CR1 |= TIM_CLKSRC_SEL_EX1;
  /* Select the Trigger selection : ETRF */
  tmpsmcr &= (uint16_t)(~((uint16_t)TIM_SMCR_TS));
  tmpsmcr |= TIM_TS_EXTRG;
  /* Write to TIMx SMCR */
  TIMx->TIM_SMCR = tmpsmcr;
}

/**
  * @brief  Configures the External clock Mode2
  * @param  TIMx: where x can be  3, 4 to select the TIM peripheral.
  * @param  TIM_ExtTRGPrescaler: The external Trigger Prescaler.
  * @param  TIM_ExtTRGPolarity: The external Trigger Polarity.
  * @param  ExtTRGFilter: External Trigger Filter.
  *   This parameter must be a value between 0x00 and 0x0F
  * @retval None
  */
void TIM_ETRClockMode2Config(TIMER_Type* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_EXT_PRESCALER(TIM_ExtTRGPrescaler));
  assert_param(IS_TIM_EXT_POLARITY(TIM_ExtTRGPolarity));
  assert_param(IS_TIM_EXT_FILTER(ExtTRGFilter));
  /* Configure the ETR Clock source */
  TIM_ETRConfig(TIMx, TIM_ExtTRGPrescaler, TIM_ExtTRGPolarity, ExtTRGFilter);
  /* Enable the External clock mode2 */
  TIMx->TIM_CR1 |= TIM_CLKSRC_SEL_EX2;
}

/**
  * @brief  Configures the TIMx External Trigger (ETR).
  * @param  TIMx: where x can be  3, 4 to select the TIM peripheral.
  * @param  TIM_ExtTRGPrescaler: The external Trigger Prescaler.
  * @param  TIM_ExtTRGPolarity: The external Trigger Polarity.
  * @param  ExtTRGFilter: External Trigger Filter.
  *   This parameter must be a value between 0x00 and 0x0F
  * @retval None
  */
void TIM_ETRConfig(TIMER_Type* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                   uint16_t ExtTRGFilter)
{
  uint16_t tmpsmcr = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_EXT_PRESCALER(TIM_ExtTRGPrescaler));
  assert_param(IS_TIM_EXT_POLARITY(TIM_ExtTRGPolarity));
  assert_param(IS_TIM_EXT_FILTER(ExtTRGFilter));
  tmpsmcr = TIMx->TIM_SMCR;
  /* Reset the ETR Bits */
  tmpsmcr &= SMCR_ETR_Mask;
  /* Set the Prescaler, the Filter value and the Polarity */
  tmpsmcr |= (uint16_t)(TIM_ExtTRGPrescaler | (uint16_t)(TIM_ExtTRGPolarity | (uint16_t)(ExtTRGFilter << (uint16_t)8)));
  /* Write to TIMx SMCR */
  TIMx->TIM_SMCR = tmpsmcr;
}

/**
  * @brief  Gets the TIMx Input Capture 0 value.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4 to select the TIM peripheral.
  * @retval Capture Compare 0 Register value.
  */
uint16_t TIM_GetCapture0(TIMER_Type* TIMx)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  /* Get the Capture 1 Register value */
  return TIMx->TIM_CAPR_CC0;
}

/**
  * @brief  Gets the TIMx Input Capture 1 value.
  * @param  TIMx: where x can be 3, 4 to select the TIM peripheral.
  * @retval Capture Compare 1 Register value.
  */
uint16_t TIM_GetCapture1(TIMER_Type* TIMx)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  /* Get the Capture 1 Register value */
  return TIMx->TIM_CAPR_CC1;
}

/**
  * @brief  Gets the TIMx Input Capture 2 value.
  * @param  TIMx: where x can be 3, 4 to select the TIM peripheral.
  * @retval Capture Compare 2 Register value.
  */
uint16_t TIM_GetCapture2(TIMER_Type* TIMx)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  /* Get the Capture 1 Register value */
  return TIMx->TIM_CAPR_CC2;
}

/**
  * @brief  Gets the TIMx Input Capture 3 value.
  * @param  TIMx: where x can be 3, 4 to select the TIM peripheral.
  * @retval Capture Compare 3 Register value.
  */
uint16_t TIM_GetCapture3(TIMER_Type* TIMx)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  /* Get the Capture 1 Register value */
  return TIMx->TIM_CAPR_CC3;
}

/**
  * @brief  Gets the TIMx Counter value.
  * @param  TIMx: where x can be 1 to 17 to select the TIM peripheral.
  * @retval Counter Register value.
  */
uint16_t TIM_GetCounter(TIMER_Type* TIMx)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  /* Get the Counter Register value */
  return TIMx->TIM_CNT;
}

/**
  * @brief  Checks whether the specified TIM flag is set or not.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  TIM_FLAG: specifies the flag to check.
  * @note   
  * @retval The new state of TIM_FLAG (SET or RESET).
  */
FlagStatus TIM_GetFlagStatus(TIMER_Type* TIMx, uint32_t TIM_FLAG)
{ 
  ITStatus bitstatus = RESET;  
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_GET_FLAG(TIM_FLAG));
  
  if ((TIMx->TIM_ISR & TIM_FLAG) != (uint32_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}

/**
  * @brief  Checks whether the TIM interrupt has occurred or not.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  TIM_IT: specifies the TIM interrupt source to check.
  * @note
  * @retval The new state of the TIM_IT(SET or RESET).
  */
ITStatus TIM_GetITStatus(TIMER_Type* TIMx, uint32_t TIM_IT)
{
  ITStatus bitstatus = RESET;  
  uint16_t itstatus = 0x0, itenable = 0x0;
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_GET_IT(TIM_IT));
   
  itstatus = TIMx->TIM_ISR & TIM_IT;
  
  itenable = TIMx->TIM_DIER & TIM_IT;
  if ((itstatus != (uint16_t)RESET) && (itenable != (uint16_t)RESET))
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}

/**
  * @brief  Gets the TIMx Prescaler value.
  * @param  TIMx: where x can be 1 to 17 to select the TIM peripheral.
  * @retval Prescaler Register value.
  */
uint16_t TIM_GetPrescaler(TIMER_Type* TIMx)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  /* Get the Prescaler Register value */
  return TIMx->TIM_PSC;
}

/**
  * @brief  Enables or disables the specified TIM interrupts.
  * @param  TIMx: where x can be 0 to 4 to select the TIMx peripheral.
  * @param  TIM_IT: specifies the TIM interrupts sources to be enabled or disabled.
  * @note 
  * @param  NewState: new state of the TIM interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM_ITConfig(TIMER_Type* TIMx, uint32_t TIM_IT, FunctionalState NewState)
{  
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_IT(TIM_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    TIMx->TIM_DIER |= TIM_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    TIMx->TIM_DIER &= (uint16_t)~TIM_IT;
  }
}

/**
  * @brief  Initializes the TIMx Channel 0 according to the specified
  *         parameters in the TIM_OCInitStruct.
  * @param  TIMx: where x can be  0, 1, 2, 3, 4 to select the TIM peripheral.
  * @param  TIM_OCInitStruct: pointer to a TIM_OCInitTypeDef structure
  *         that contains the configuration information for the specified TIM peripheral.
  * @retval None
  */
void TIM_OC0Init(TIMER_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
{
    uint32_t tmpcr2 = 0;
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_TIM_OC_MODE(TIM_OCInitStruct->TIM_OCMode));
    assert_param(IS_TIM_OUTPUT_STATE(TIM_OCInitStruct->TIM_OutputState));
    assert_param(IS_TIM_OC_POLARITY(TIM_OCInitStruct->TIM_OCPolarity)); 
    assert_param(IS_TIM_OCN_POLARITY(TIM_OCInitStruct->TIM_OCPolarity)); 
    assert_param(IS_TIM_BKIDLE_STATE(TIM_BDTRInitStruct->TIM_BreakIdleState));
    assert_param(IS_TIM_BKNIDLE_STATE(TIM_BDTRInitStruct->TIM_BreakNIdleState)); 

    tmpcr2 =  TIMx->TIM_CCCR;
    if((TIMx == TIMER0) || (TIMx == TIMER1)|| (TIMx == TIMER2) || (TIMx == TIMER3)||(TIMx == TIMER4)) 
    {
        TIMx->TIM_CR2 |= ((TIM_OCInitStruct->TIM_CMPMode) << 7);
        TIMx->TIM_CR2 |= ((TIM_OCInitStruct->TIM_OCMode) << 8);
    /* Select the Counter Mode */
        tmpcr2  |=  ((TIM_OCInitStruct->TIM_CMP_PRELOAD_EN)<<20)   | \
                    ((TIM_OCInitStruct->TIM_CMP_EN)<<16)           | \
                    ((TIM_OCInitStruct->TIM_OutputState)<<0)       | \
                    ((TIM_OCInitStruct->TIM_OCPolarity)<<4);
    }  
    if((TIMx == TIMER3)||(TIMx == TIMER4))
    {
        tmpcr2  |=  ((TIM_OCInitStruct->TIM_OutputNState)<<8)  | \
                        ((TIM_OCInitStruct->TIM_OCNPolarity)<<12);
        TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_DT_EN << 24);
        TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_DEAD_TIME << 16);   
        TIMx->TIM_BKOIS |=  ((TIM_OCInitStruct->TIM_BreakIdleState)<<4)  | \
                        ((TIM_OCInitStruct->TIM_BreakNIdleState));   
    }   
    TIMx->TIM_CCCR = tmpcr2;
    TIMx->TIM_CMPR_CC0 = TIM_OCInitStruct->TIM_Pulse;
 
    TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_MOE_EN << 15);
}

/**
  * @brief  Initializes the TIMx Channel 1 according to the specified
  *         parameters in the TIM_OCInitStruct.
  * @param  TIMx: where x can be  3, 4 to select the TIM peripheral.
  * @param  TIM_OCInitStruct: pointer to a TIM_OCInitTypeDef structure
  *         that contains the configuration information for the specified TIM peripheral.
  * @retval None
  */
void TIM_OC1Init(TIMER_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
{
    uint32_t tmpcr2 = 0;
    /* Check the parameters */
    assert_param(IS_TIM_34_PERIPH(TIMx));
    assert_param(IS_TIM_OC_MODE(TIM_OCInitStruct->TIM_OCMode));
    assert_param(IS_TIM_OUTPUT_STATE(TIM_OCInitStruct->TIM_OutputState));
    assert_param(IS_TIM_OC_POLARITY(TIM_OCInitStruct->TIM_OCPolarity)); 
    assert_param(IS_TIM_OCN_POLARITY(TIM_OCInitStruct->TIM_OCPolarity)); 
    assert_param(IS_TIM_BKIDLE_STATE(TIM_BDTRInitStruct->TIM_BreakIdleState));
    assert_param(IS_TIM_BKNIDLE_STATE(TIM_BDTRInitStruct->TIM_BreakNIdleState)); 

    tmpcr2 =  TIMx->TIM_CCCR;
    if((TIMx == TIMER0) || (TIMx == TIMER1)|| (TIMx == TIMER2) || (TIMx == TIMER3)||(TIMx == TIMER4)) 
    {
    /* Select the Counter Mode */
    }  
    if((TIMx == TIMER3)||(TIMx == TIMER4))
    {
        TIMx->TIM_CR2 |= ((TIM_OCInitStruct->TIM_CMPMode) << 7);
        TIMx->TIM_CR2 |= ((TIM_OCInitStruct->TIM_OCMode) << 9);
        tmpcr2  |=  ((TIM_OCInitStruct->TIM_CMP_PRELOAD_EN)<<21)   | \
                    ((TIM_OCInitStruct->TIM_CMP_EN)<<17)           | \
                    ((TIM_OCInitStruct->TIM_OutputState)<<1)       | \
                    ((TIM_OCInitStruct->TIM_OutputNState)<<9)      | \
                    ((TIM_OCInitStruct->TIM_OCPolarity)<<5)        | \
                    ((TIM_OCInitStruct->TIM_OCNPolarity)<<13);
        TIMx->TIM_BKOIS |=  ((TIM_OCInitStruct->TIM_BreakIdleState)<<5)  | \
                        ((TIM_OCInitStruct->TIM_BreakNIdleState)<<1);  

        TIMx->TIM_CMPR_CC1 = TIM_OCInitStruct->TIM_Pulse;
        TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_DT_EN << 25);
        TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_DEAD_TIME << 16);                    
    }   
    TIMx->TIM_CCCR = tmpcr2;

    TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_MOE_EN << 15);
}

/**
  * @brief  Initializes the TIMx Channel 2 according to the specified
  *         parameters in the TIM_OCInitStruct.
  * @param  TIMx: where x can be  3, 4 to select the TIM peripheral.
  * @param  TIM_OCInitStruct: pointer to a TIM_OCInitTypeDef structure
  *         that contains the configuration information for the specified TIM peripheral.
  * @retval None
  */
void TIM_OC2Init(TIMER_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
{
    uint32_t tmpcr2 = 0;
    /* Check the parameters */
    assert_param(IS_TIM_34_PERIPH(TIMx));
    assert_param(IS_TIM_OC_MODE(TIM_OCInitStruct->TIM_OCMode));
    assert_param(IS_TIM_OUTPUT_STATE(TIM_OCInitStruct->TIM_OutputState));
    assert_param(IS_TIM_OC_POLARITY(TIM_OCInitStruct->TIM_OCPolarity)); 
    assert_param(IS_TIM_OCN_POLARITY(TIM_OCInitStruct->TIM_OCPolarity)); 
    assert_param(IS_TIM_BKIDLE_STATE(TIM_BDTRInitStruct->TIM_BreakIdleState));
    assert_param(IS_TIM_BKNIDLE_STATE(TIM_BDTRInitStruct->TIM_BreakNIdleState)); 

    tmpcr2 =  TIMx->TIM_CCCR;
    if((TIMx == TIMER0) || (TIMx == TIMER1)|| (TIMx == TIMER2) || (TIMx == TIMER3)||(TIMx == TIMER4)) 
    {
    /* Select the Counter Mode */
    }  
    if((TIMx == TIMER3)||(TIMx == TIMER4))
    {
        TIMx->TIM_CR2 |= ((TIM_OCInitStruct->TIM_CMPMode) << 7);
        TIMx->TIM_CR2 |= ((TIM_OCInitStruct->TIM_OCMode) << 10);
        tmpcr2  |=  ((TIM_OCInitStruct->TIM_CMP_PRELOAD_EN)<<22)   | \
                    ((TIM_OCInitStruct->TIM_CMP_EN)<<18)           | \
                    ((TIM_OCInitStruct->TIM_OutputState)<<2)       | \
                    ((TIM_OCInitStruct->TIM_OutputNState)<<10)     | \
                    ((TIM_OCInitStruct->TIM_OCPolarity)<<6)        | \
                    ((TIM_OCInitStruct->TIM_OCNPolarity)<<14);
        TIMx->TIM_BKOIS |=  ((TIM_OCInitStruct->TIM_BreakIdleState)<<6)  | \
                        ((TIM_OCInitStruct->TIM_BreakNIdleState)<<2);  

        TIMx->TIM_CMPR_CC2 = TIM_OCInitStruct->TIM_Pulse;
        TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_DT_EN << 26);
        TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_DEAD_TIME << 16);                    
    }   
    TIMx->TIM_CCCR = tmpcr2;

    TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_MOE_EN << 15);
}

/**
  * @brief  Initializes the TIMx Channel 3 according to the specified
  *         parameters in the TIM_OCInitStruct.
  * @param  TIMx: where x can be  3, 4 to select the TIM peripheral.
  * @param  TIM_OCInitStruct: pointer to a TIM_OCInitTypeDef structure
  *         that contains the configuration information for the specified TIM peripheral.
  * @retval None
  */
void TIM_OC3Init(TIMER_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
{
    uint32_t tmpcr2 = 0;
    /* Check the parameters */
    assert_param(IS_TIM_34_PERIPH(TIMx));
    assert_param(IS_TIM_OC_MODE(TIM_OCInitStruct->TIM_OCMode));
    assert_param(IS_TIM_OUTPUT_STATE(TIM_OCInitStruct->TIM_OutputState));
    assert_param(IS_TIM_OC_POLARITY(TIM_OCInitStruct->TIM_OCPolarity)); 
    assert_param(IS_TIM_OCN_POLARITY(TIM_OCInitStruct->TIM_OCPolarity)); 
    assert_param(IS_TIM_BKIDLE_STATE(TIM_BDTRInitStruct->TIM_BreakIdleState));
    assert_param(IS_TIM_BKNIDLE_STATE(TIM_BDTRInitStruct->TIM_BreakNIdleState)); 

    tmpcr2 =  TIMx->TIM_CCCR;
    if((TIMx == TIMER0) || (TIMx == TIMER1)|| (TIMx == TIMER2) || (TIMx == TIMER3)||(TIMx == TIMER4)) 
    {
    /* Select the Counter Mode */
    }  
    if((TIMx == TIMER3)||(TIMx == TIMER4))
    {
        TIMx->TIM_CR2 |= ((TIM_OCInitStruct->TIM_CMPMode) << 7);
        TIMx->TIM_CR2 |= ((TIM_OCInitStruct->TIM_OCMode) << 11);
        tmpcr2  |=  ((TIM_OCInitStruct->TIM_CMP_PRELOAD_EN)<<23)   | \
                    ((TIM_OCInitStruct->TIM_CMP_EN)<<19)           | \
                    ((TIM_OCInitStruct->TIM_OutputState)<<3)       | \
                    ((TIM_OCInitStruct->TIM_OCPolarity)<<7);
        TIMx->TIM_BKOIS |=  ((TIM_OCInitStruct->TIM_BreakIdleState)<<7); 

        TIMx->TIM_CMPR_CC3 = TIM_OCInitStruct->TIM_Pulse;                 
    }   
    TIMx->TIM_CCCR = tmpcr2;
    TIMx->TIM_BDTR |= (TIM_OCInitStruct->TIM_MOE_EN << 15);
}

/**
  * @brief  Configures the TIMx channel 0 polarity.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  TIM_OCPolarity: specifies the OC0 Polarity
  *   This parameter can be one of the following values:
  * @retval None
  */
void TIM_OC0PolarityConfig(TIMER_Type* TIMx, uint16_t TIM_OCPolarity)
{
  uint32_t tmpccer = 0;
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_IC_POLARITY_LITE(TIM_OCPolarity)); 
  tmpccer = TIMx->TIM_ICMR;
  /* Set or Reset the CC0P Bit */
  tmpccer &= (uint16_t)~((uint16_t)(TIM_CAP_CC0P));
  tmpccer |= (uint16_t)(TIM_OCPolarity << 2);
  /* Write to TIMx CCER register */
  TIMx->TIM_ICMR = tmpccer;  
}

/**
  * @brief  Configures the TIMx channel 1 polarity.
  * @param  TIMx: where x can be 3 to 4 to select the TIM peripheral.
  * @param  TIM_OCPolarity: specifies the OC1 Polarity
  *   This parameter can be one of the following values:
  * @retval None
  */
void TIM_OC1PolarityConfig(TIMER_Type* TIMx, uint16_t TIM_OCPolarity)
{
  uint32_t tmpccer = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_IC_POLARITY_LITE(TIM_OCPolarity)); 
  tmpccer = TIMx->TIM_ICMR;
  /* Set or Reset the CC0P Bit */
  tmpccer &= (uint16_t)~((uint16_t)(TIM_CAP_CC1P));
  tmpccer |= (uint16_t)(TIM_OCPolarity << 10);
  /* Write to TIMx CCER register */
  TIMx->TIM_ICMR = tmpccer;  
}

/**
  * @brief  Configures the TIMx channel 2 polarity.
  * @param  TIMx: where x can be 3 to 4 to select the TIM peripheral.
  * @param  TIM_OCPolarity: specifies the OC2 Polarity
  *   This parameter can be one of the following values:
  * @retval None
  */
void TIM_OC2PolarityConfig(TIMER_Type* TIMx, uint16_t TIM_OCPolarity)
{
  uint32_t tmpccer = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_IC_POLARITY_LITE(TIM_OCPolarity)); 
  tmpccer = TIMx->TIM_ICMR;
  /* Set or Reset the CC0P Bit */
  tmpccer &= (uint16_t)~((uint16_t)(TIM_CAP_CC2P));
  tmpccer |= (uint16_t)(TIM_OCPolarity << 18);
  /* Write to TIMx CCER register */
  TIMx->TIM_ICMR = tmpccer;  
}

/**
  * @brief  Configures the TIMx channel 3 polarity.
  * @param  TIMx: where x can be 3 to 4 to select the TIM peripheral.
  * @param  TIM_OCPolarity: specifies the OC3 Polarity
  *   This parameter can be one of the following values:
  * @retval None
  */
void TIM_OC3PolarityConfig(TIMER_Type* TIMx, uint16_t TIM_OCPolarity)
{
  uint32_t tmpccer = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_IC_POLARITY_LITE(TIM_OCPolarity)); 
  tmpccer = TIMx->TIM_ICMR;
  /* Set or Reset the CC0P Bit */
  tmpccer &= (uint16_t)~((uint16_t)(TIM_CAP_CC3P));
  tmpccer |= (uint16_t)(TIM_OCPolarity << 26);
  /* Write to TIMx CCER register */
  TIMx->TIM_ICMR = tmpccer;  
}

/**
  * @brief  Enables or disables the TIMx peripheral Preload register on CCR0.
  * @param  TIMx: where x can be 3, 4, to select the TIM peripheral.
  * @param  TIM_OCPreload: new state of the TIMx peripheral Preload register
  *   This parameter can be one of the following values:
  *     @arg TIM_OCPreload_Enable
  *     @arg TIM_OCPreload_Disable
  * @retval None
  */
void TIM_OC0PreloadConfig(TIMER_Type* TIMx, uint16_t TIM_OCPreload)
{
  uint32_t tmpccmr2 = 0;
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_OCPRELOAD_STATE(TIM_OCPreload));
  tmpccmr2 = TIMx->TIM_CCCR;
  /* Reset the OC0PE Bit */
  tmpccmr2 &= (uint32_t)~((uint32_t)TIM_CCCR_OC0PE);
  /* Enable or Disable the Output Compare Preload feature */
  tmpccmr2 |= (uint16_t)(TIM_OCPreload << 20);
  /* Write to TIMx CCMR2 register */
  TIMx->TIM_CCCR = tmpccmr2;
}

/**
  * @brief  Enables or disables the TIMx peripheral Preload register on CCR1.
  * @param  TIMx: where x can be 3, 4, to select the TIM peripheral.
  * @param  TIM_OCPreload: new state of the TIMx peripheral Preload register
  *   This parameter can be one of the following values:
  *     @arg TIM_OCPreload_Enable
  *     @arg TIM_OCPreload_Disable
  * @retval None
  */
void TIM_OC1PreloadConfig(TIMER_Type* TIMx, uint16_t TIM_OCPreload)
{
  uint32_t tmpccmr2 = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_OCPRELOAD_STATE(TIM_OCPreload));
  tmpccmr2 = TIMx->TIM_CCCR;
  /* Reset the OC1PE Bit */
  tmpccmr2 &= (uint32_t)~((uint32_t)TIM_CCCR_OC1PE);
  /* Enable or Disable the Output Compare Preload feature */
  tmpccmr2 |= (uint16_t)(TIM_OCPreload << 21);
  /* Write to TIMx CCMR2 register */
  TIMx->TIM_CCCR = tmpccmr2;
}

/**
  * @brief  Enables or disables the TIMx peripheral Preload register on CCR2.
  * @param  TIMx: where x can be 3, 4, to select the TIM peripheral.
  * @param  TIM_OCPreload: new state of the TIMx peripheral Preload register
  *   This parameter can be one of the following values:
  *     @arg TIM_OCPreload_Enable
  *     @arg TIM_OCPreload_Disable
  * @retval None
  */
void TIM_OC2PreloadConfig(TIMER_Type* TIMx, uint16_t TIM_OCPreload)
{
  uint32_t tmpccmr2 = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_OCPRELOAD_STATE(TIM_OCPreload));
  tmpccmr2 = TIMx->TIM_CCCR;
  /* Reset the OC2PE Bit */
  tmpccmr2 &= (uint32_t)~((uint32_t)TIM_CCCR_OC2PE);
  /* Enable or Disable the Output Compare Preload feature */
  tmpccmr2 |= (uint16_t)(TIM_OCPreload << 22);
  /* Write to TIMx CCMR2 register */
  TIMx->TIM_CCCR = tmpccmr2;
}

/**
  * @brief  Enables or disables the TIMx peripheral Preload register on CCR3.
  * @param  TIMx: where x can be 3, 4, to select the TIM peripheral.
  * @param  TIM_OCPreload: new state of the TIMx peripheral Preload register
  *   This parameter can be one of the following values:
  *     @arg TIM_OCPreload_Enable
  *     @arg TIM_OCPreload_Disable
  * @retval None
  */
void TIM_OC3PreloadConfig(TIMER_Type* TIMx, uint16_t TIM_OCPreload)
{
  uint32_t tmpccmr2 = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_OCPRELOAD_STATE(TIM_OCPreload));
  tmpccmr2 = TIMx->TIM_CCCR;
  /* Reset the OC3PE Bit */
  tmpccmr2 &= (uint32_t)~((uint32_t)TIM_CCCR_OC3PE);
  /* Enable or Disable the Output Compare Preload feature */
  tmpccmr2 |= (uint16_t)(TIM_OCPreload << 23);
  /* Write to TIMx CCMR2 register */
  TIMx->TIM_CCCR = tmpccmr2;
}

/**
  * @brief  Configures the TIMx EGR.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  Prescaler: specifies the Prescaler Register value
  * @param  TIM_PSCReloadMode: specifies the TIM Prescaler Reload mode
  *     @arg .
  *     @arg 
  * @retval None
  */
void TIM_EGRConfig(TIMER_Type* TIMx, uint16_t TIM_ET)
{
  uint16_t tmpccer = 0;
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  tmpccer = TIMx->TIM_EGR;
  tmpccer |= TIM_ET;

  TIMx->TIM_EGR = tmpccer;
}

/**
  * @brief  Selects the TIMx peripheral Capture Compare DMA source.
  * @param  TIMx: where x can be  3, 4 to select 
  *         the TIM peripheral.
  * @param  NewState: new state of the Capture Compare DMA source
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM_SelectCCDMA(TIMER_Type* TIMx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* Set the CCDS Bit */
    TIMx->TIM_CR2 |= TIM_CR2_CCDS;
  }
  else
  {
    /* Reset the CCDS Bit */
    TIMx->TIM_CR2 &= (uint16_t)~((uint16_t)TIM_CR2_CCDS);
  }
}

/**
  * @brief  Selects the Input Trigger source
  * @param  TIMx: where x can be 3, 4 to select the TIM peripheral.
  * @param  TIM_InputTriggerSource: The Input Trigger source.
  *   This parameter can be one of the following values:
  *     @arg TIM_TS_CC0F_RF: Internal Trigger 0
  *     @arg TIM_TS_CC0FP0: Internal Trigger 1
  *     @arg TIM_TS_CC1FP1: Internal Trigger 2
  *     @arg TIM_TS_EXTRG: Internal Trigger 3
  *     @arg TIM_TS_T2FF: TI1 Edge Detector
  * @retval None
  */
void TIM_SelectInputTrigger(TIMER_Type* TIMx, uint16_t TIM_InputTriggerSource)
{
  uint32_t tmpsmcr = 0;
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_TRIGGER_SELECTION(TIM_InputTriggerSource));
  /* Get the TIMx SMCR register value */
  tmpsmcr = TIMx->TIM_SMCR;
  /* Reset the TS Bits */
  tmpsmcr &= (uint16_t)(~((uint16_t)TIM_SMCR_TS));
  /* Set the Input Trigger source */
  tmpsmcr |= TIM_InputTriggerSource;
  /* Write to TIMx SMCR */
  TIMx->TIM_SMCR = tmpsmcr;
}

/**
  * @brief  Selects the TIMx's One Pulse Mode.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  TIM_OPMode: specifies the OPM Mode to be used.
  *   This parameter can be one of the following values:
  *     @arg TIM_OPMode_Single
  *     @arg TIM_OPMode_Repetitive
  * @retval None
  */
void TIM_SelectOnePulseMode(TIMER_Type* TIMx, uint16_t TIM_OPMode)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_OPM_MODE(TIM_OPMode));
  /* Reset the OPM Bit */
  TIMx->TIM_CR1 &= (uint16_t)~((uint16_t)TIM_CR1_OPM);
  /* Configure the OPM Mode */
  TIMx->TIM_CR1 |= TIM_OPMode;
}


/**
  * @brief  COMPMode1 output state.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  
  *   This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM_OC0_IDConfig(TIMER_Type* TIMx, uint16_t TIM_OCxID)
{
    uint16_t tmpccer = 0;
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_TIM_OCx_ID(TIM_OCxID));
    tmpccer = TIMx->TIM_ID;
    /* Set or Reset the CC0ID Bit */
    tmpccer &= (uint16_t)~((uint16_t)0x0001);
    tmpccer |= TIM_OCxID << 0;
    /* Write to TIMx TIM_ID register */
    TIMx->TIM_ID = tmpccer;
}

/**
  * @brief  COMPMode1 output state.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  
  *   This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM_OC1_IDConfig(TIMER_Type* TIMx, uint16_t TIM_OCxID)
{
    uint16_t tmpccer = 0;
    /* Check the parameters */
    assert_param(IS_TIM_34_PERIPH(TIMx));
    assert_param(IS_TIM_OCx_ID(TIM_OCxID));
    tmpccer = TIMx->TIM_ID;
    /* Set or Reset the CC0ID Bit */
    tmpccer &= (uint16_t)~((uint16_t)0x0002);
    tmpccer |= TIM_OCxID << 1;
    /* Write to TIMx TIM_ID register */
    TIMx->TIM_ID = tmpccer;
}

/**
  * @brief  COMPMode1 output state.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  
  *   This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM_OC2_IDConfig(TIMER_Type* TIMx, uint16_t TIM_OCxID)
{
    uint16_t tmpccer = 0;
    /* Check the parameters */
    assert_param(IS_TIM_34_PERIPH(TIMx));
    assert_param(IS_TIM_OCx_ID(TIM_OCxID));
    tmpccer = TIMx->TIM_ID;
    /* Set or Reset the CC0ID Bit */
    tmpccer &= (uint16_t)~((uint16_t)0x0004);
    tmpccer |= TIM_OCxID << 2;
    /* Write to TIMx TIM_ID register */
    TIMx->TIM_ID = tmpccer;
}

/**
  * @brief  COMPMode1 output state.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  
  *   This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM_OC3_IDConfig(TIMER_Type* TIMx, uint16_t TIM_OCxID)
{
    uint16_t tmpccer = 0;
    /* Check the parameters */
    assert_param(IS_TIM_34_PERIPH(TIMx));
    assert_param(IS_TIM_OCx_ID(TIM_OCxID));
    tmpccer = TIMx->TIM_ID;
    /* Set or Reset the CC0ID Bit */
    tmpccer &= (uint16_t)~((uint16_t)0x0008);
    tmpccer |= TIM_OCxID << 3;
    /* Write to TIMx TIM_ID register */
    TIMx->TIM_ID = tmpccer;
}

/**
  * @brief  Selects the TIMx Trigger Output Enable.
  * @param  TIMx: where x can be 0, 1, 2, 3, 4to select the TIM peripheral.
  * @param  TIM_TRGOSource: specifies the Trigger Output source.
  *   This paramter can be one of the following values:
  *
  *  - For all TIMx
  *     @arg TIM_TRG0_EN: CC0_TRGO_EN.
  *  - For TIM3 and TIM4
  *     @arg TIM_TRG1_EN: CC1_TRGO_EN.
  *     @arg TIM_TRG2_EN: CC2_TRGO_EN.
  *     @arg TIM_TRG3_EN: CC3_TRGO_EN.
  *
  * @retval None
  */
void TIM_SelectOutputTrigger(TIMER_Type* TIMx, uint16_t TIM_TRGOSource)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_TRGO_SOURCE(TIM_TRGOSource));
  /* Reset the MMS Bits */
  TIMx->TIM_CR2 &= (uint16_t)~((uint16_t)TIM_CR2_TRGOEN);
  /* Select the TRGO source */
  TIMx->TIM_CR2 |=  TIM_TRGOSource;
}

/**
  * @brief  Selects the TIMx Slave Mode.
  * @param  TIMx: where x can be 3, 4 to select the TIM peripheral.
  * @param  TIM_SlaveMode: specifies the Timer Slave Mode.
  *   This parameter can be one of the following values:
  *     @arg TIM_SlaveMode_Reset: Rising edge of the selected trigger signal (TRGI) re-initializes
  *                               the counter and triggers an update of the registers.
  *     @arg TIM_SlaveMode_Gated:     The counter clock is enabled when the trigger signal (TRGI) is high.
  *     @arg TIM_SlaveMode_Trigger:   The counter starts at a rising edge of the trigger TRGI.
  *     @arg TIM_SlaveMode_Reserve:   Reserve.
  * @retval None
  */
void TIM_SelectSlaveMode(TIMER_Type* TIMx, uint16_t TIM_SlaveMode)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  assert_param(IS_TIM_SLAVE_MODE(TIM_SlaveMode));
 /* Reset the SMS Bits */
  TIMx->TIM_SMCR &= (uint16_t)~((uint16_t)TIM_SMCR_SMS);
  /* Select the Slave Mode */
  TIMx->TIM_SMCR |= TIM_SlaveMode;
}

/**
  * @brief  Sets the TIMx Counter Register value
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  Counter: specifies the Counter register new value.
  * @retval None
  */
void TIM_SetCounter(TIMER_Type* TIMx, uint16_t Counter)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  /* Set the Counter Register value */
  TIMx->TIM_CNT = Counter;
}

/**
  * @brief  Sets the TIMx Autoreload Register value
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  Autoreload: specifies the Autoreload register new value.
  * @retval None
  */
void TIM_SetAutoreload(TIMER_Type* TIMx, uint16_t Autoreload)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  /* Set the Autoreload Register value */
  TIMx->TIM_ARR = Autoreload;
}

/**
  * @brief  Sets the TIMx Capture Compare0 Register value
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  Compare4: specifies the Capture Compare0 register new value.
  * @retval None
  */
void TIM_SetCompare0(TIMER_Type* TIMx, uint16_t Compare0)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  /* Set the Capture Compare2 Register value */
  TIMx->TIM_CMPR_CC0 = Compare0;
}


/**
  * @brief  Sets the TIMx Capture Compare1 Register value
  * @param  TIMx: where x can be 3 to 4 to select the TIM peripheral.
  * @param  Compare4: specifies the Capture Compare1 register new value.
  * @retval None
  */
void TIM_SetCompare1(TIMER_Type* TIMx, uint16_t Compare1)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  /* Set the Capture Compare2 Register value */
  TIMx->TIM_CMPR_CC1 = Compare1;
}

/**
  * @brief  Sets the TIMx Capture Compare2 Register value
  * @param  TIMx: where x can be 3 to 4 to select the TIM peripheral.
  * @param  Compare4: specifies the Capture Compare2 register new value.
  * @retval None
  */
void TIM_SetCompare2(TIMER_Type* TIMx, uint16_t Compare2)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  /* Set the Capture Compare2 Register value */
  TIMx->TIM_CMPR_CC2 = Compare2;
}

/**
  * @brief  Sets the TIMx Capture Compare3 Register value
  * @param  TIMx: where x can be 3 to 4 to select the TIM peripheral.
  * @param  Compare4: specifies the Capture Compare3 register new value.
  * @retval None
  */
void TIM_SetCompare3(TIMER_Type* TIMx, uint16_t Compare3)
{
  /* Check the parameters */
  assert_param(IS_TIM_34_PERIPH(TIMx));
  /* Set the Capture Compare2 Register value */
  TIMx->TIM_CMPR_CC3 = Compare3;
}

/**
  * @brief  Initializes the TIMx Time Base Unit peripheral according to 
  *         the specified parameters in the TIM_TimeBaseInitStruct.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  TIM_TimeBaseInitStruct: pointer to a TIM_TimeBaseInitTypeDef
  *         structure that contains the configuration information for the 
  *         specified TIM peripheral.
  * @retval None
  */
void TIM_TimeBaseInit(TIMER_Type* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
    uint32_t tmpcr1 = 0;
	  
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_TIM_COUNTER_MODE(TIM_TimeBaseInitStruct->TIM_CNT_DIR));  
    assert_param(IS_TIM_CLKSRC_SEL(TIM_TimeBaseInitStruct->TIM_CLKSRC_SEL_IN));
    assert_param(IS_TIM_ALIGN_MODE(TIM_TimeBaseInitStruct->TIM_ALIGN_MODE));  
    assert_param(IS_TIM_IC_RELOAD_MODE(TIM_TimeBaseInitStruct->TIM_RELOAD_MODE)); 
    assert_param(IS_TIM_IC_TFF_Edge(TIM_TimeBaseInitStruct->TIM_TFFEDGE_SEL));  


    tmpcr1 = TIMx->TIM_CR1;    
    if((TIMx == TIMER0) || (TIMx == TIMER1)|| (TIMx == TIMER2) || (TIMx == TIMER3)||(TIMx == TIMER4)) 
    {
    /* Select the Counter Mode */
        tmpcr1  |=  ((TIM_TimeBaseInitStruct->TIM_REPEAT_EN)<<15) | \
                    ((TIM_TimeBaseInitStruct->TIM_OPM_EN)<<14)    | \
                    ((TIM_TimeBaseInitStruct->TIM_ARPE_EN)<<13)   | \
                    ((TIM_TimeBaseInitStruct->TIM_UDIS_EN)<<12)   | \
                    TIM_TimeBaseInitStruct->TIM_CNT_DIR           | \
                    TIM_TimeBaseInitStruct->TIM_ALIGN_MODE        | \
                    TIM_TimeBaseInitStruct->TIM_CLKSRC_SEL;        
    }  
    if((TIMx == TIMER3)||(TIMx == TIMER4))
    {
        tmpcr1  |=  ((TIM_TimeBaseInitStruct->TIM_T2EXM_EN)<<16)  | \
                    TIM_TimeBaseInitStruct->TIM_TFFEDGE_SEL       | \
                    TIM_TimeBaseInitStruct->TIM_RELOAD_MODE;
    }
    TIMx->TIM_CR1 = tmpcr1;		
    TIMx->TIM_RCR = TIM_TimeBaseInitStruct->TIM_RepetitionCounter;
    /* Set the Prescaler value */
    TIMx->TIM_PSC = TIM_TimeBaseInitStruct->TIM_Prescaler;
    /* Set the Autoreload value */
    TIMx->TIM_ARR = TIM_TimeBaseInitStruct->TIM_Period;
}

/**
  * @brief  Enables or Disables the TIMx Update event.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  NewState: new state of the TIMx UDIS bit
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM_UpdateDisableConfig(TIMER_Type* TIMx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* Set the Update Disable Bit */
    TIMx->TIM_CR1 |= TIM_CR1_UDIS;
  }
  else
  {
    /* Reset the Update Disable Bit */
    TIMx->TIM_CR1 &= (uint16_t)~((uint16_t)TIM_CR1_UDIS);
  }
}

/**
  * @brief  Configures the TIMx Update Request Interrupt source.
  * @param  TIMx: where x can be 0 to 4 to select the TIM peripheral.
  * @param  TIM_UpdateSource: specifies the Update source.
  *   This parameter can be one of the following values:
  *     @arg TIM_UpdateSource_Regular: Source of update is the counter overflow/underflow
                                       or the setting of UG bit, or an update generation
                                       through the slave mode controller.
  *     @arg TIM_UpdateSource_Global: Source of update is counter overflow/underflow.
  * @retval None
  */
void TIM_UpdateRequestConfig(TIMER_Type* TIMx, uint16_t TIM_UpdateSource)
{
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_UPDATE_SOURCE(TIM_UpdateSource));
  if (TIM_UpdateSource != TIM_UpdateSource_Global)
  {
    /* Set the URS Bit */
    TIMx->TIM_CR1 |= TIM_CR1_URS;
  }
  else
  {
    /* Reset the URS Bit */
    TIMx->TIM_CR1 &= (uint16_t)~((uint16_t)TIM_CR1_URS);
  }
}



