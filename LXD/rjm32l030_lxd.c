/**
  ******************************************************************************
  * @file    rjm32l030_lxd.c
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
#include "rjm32l030_lxd.h"

/**
  * @brief  Initializes the LCD Base Unit peripheral according to 
  *         the specified parameters in the TIM_TimeBaseInitStruct.
  * @param  LXD_LCDBaseInitTypeDef: pointer to a LXD_LCDBaseInitTypeDef
  *         structure that contains the configuration information for the 
  *         specified LCD peripheral.
  * @retval None
  */
void LXD_LCDBaseInit(LXD_LCDBaseInitTypeDef* LXD_LCDBaseStructure)
{ 
    uint32_t tmpccer = 0;
    /* Check the parameters */
    assert_param(IS_LXD_FastCharge_EN(LXD_LCDBaseStructure.LXD_LcdFastChargeState));  
    assert_param(IS_LXD_ChargeTime_SEL(LXD_LCDBaseStructure.LXD_LcdChargeTime)); 
    assert_param(IS_LXD_CurrentLevel_SEL(LXD_LCDBaseStructure.LXD_LcdCurrentLevel));  
    assert_param(IS_LXD_LcdBias_SEL(LXD_LCDBaseStructure.LXD_LcdBias)); 
    assert_param(IS_LXD_BrightnessLevel_SEL(LXD_LCDBaseStructure.LXD_LcdBrightnessLevel)); 
    
    tmpccer = LXD->LXD_CON;
    tmpccer |= ((LXD_LCDBaseStructure->LXD_LcdFastChargeState)<<4);
    tmpccer |= ((LXD_LCDBaseStructure->LXD_LcdChargeTime));
    tmpccer |= ((LXD_LCDBaseStructure->LXD_LcdCurrentLevel)<<13);
    tmpccer |= ((LXD_LCDBaseStructure->LXD_LcdBias)<<11);
    tmpccer |= ((LXD_LCDBaseStructure->LXD_LcdBrightnessLevel)<<8);
    tmpccer |= ((LXD_LCDBaseStructure->LXD_LcdDiv)<<16);
    LXD->LXD_CON = tmpccer;
}

/**
  * @brief  Initializes the LED Base Unit peripheral according to 
  *         the specified parameters in the TIM_TimeBaseInitStruct.
  * @param  LXD_LEDBaseInitTypeDef: pointer to a LXD_LCDBaseInitTypeDef
  *         structure that contains the configuration information for the 
  *         specified LED peripheral.
  * @retval None
  */
void LXD_LEDBaseInit(LXD_LEDBaseInitTypeDef* LXD_LEDBaseStructure)
{ 
    uint32_t tmpccer = 0;   
    /* Check the parameters */
    assert_param(IS_LXD_LedComLevel_SEL(LXD_LEDBaseStructure.LXD_LedComLevel));  
    assert_param(IS_LXD_LedSegLevel_SEL(LXD_LEDBaseStructure.LXD_LedSegLevel)); 
    assert_param(IS_LXD_LEDBrightnessLevel_SEL(LXD_LEDBaseStructure.LXD_LedBrightnessLevel));  
    
    tmpccer = LXD->LXD_CON;
    tmpccer |= ((LXD_LEDBaseStructure->LXD_LedComLevel)<<15);
    tmpccer |= ((LXD_LEDBaseStructure->LXD_LedSegLevel)<<14);
    tmpccer |= ((LXD_LEDBaseStructure->LXD_LedBrightnessLevel)<<8);    
    tmpccer |= ((LXD_LEDBaseStructure->LXD_LedDiv)<<16);
    LXD->LXD_CON = tmpccer;
}

/**
  * @brief  Enables or disables the specified LXD peripheral.
  * @param  LXD_LXDMODE: LCD OR LED.
  * @param  NewState: new state of the LXD peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void LXD_Cmd(uint8_t LXD_LXDMODE, FunctionalState NewState)
{
  LXD->LXD_CON |=  LXD_LXDMODE; 
  if (NewState != DISABLE)
  {
    /* Enable the LXD */
    LXD->LXD_CON |= (uint8_t)0x20;
  }
  else
  {
    /* Disable the LXD */
    LXD->LXD_CON &= (uint8_t)(~((uint8_t)0x20));
  }
}

/**
  // * @brief  LCD or LED COM Sel.
  * @param  comsel: 
  * @retval None
  */
void LXD_LcdOrLedComIoSel(uint8_t comsel)
{
  LXD->LXD_COM |= comsel;     
}

/**
  // * @brief  LCD or LED SEG Sel.
  * @param  seg0sel: 
  * @retval None
  */
void LXD_LcdOrLedSeg0IoSel(uint32_t seg0sel)
{
  LXD->LXD_SEG |= seg0sel;
  if(seg0sel & 0xF0000000)
  {
    LXD->LXD_COM |= (((seg0sel)&(0xF0000000)) >> 20);
  }
}


