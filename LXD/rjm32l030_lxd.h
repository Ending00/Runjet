#ifndef __RJM32L030_LXD_H
#define __RJM32L030_LXD_H
#include "rjm32l030.h"

typedef struct 
{
    uint8_t  LXD_LcdFastChargeState;        /*  LCD的快充使能或不使能    */
    uint8_t  LXD_LcdChargeTime;             /*  LCD的充电时间            */
    uint8_t  LXD_LcdCurrentLevel;           /*  LCD的驱动电流            */
    uint8_t  LXD_LcdBias;                   /*  LCD的偏置电压            */
    uint8_t  LXD_LcdBrightnessLevel;        /*  LCD的亮度等级            */
    uint16_t LXD_LcdDiv;                    /*  LCD的显示分频            */

}LXD_LCDBaseInitTypeDef;

typedef struct 
{
    uint8_t  LXD_LedComLevel;               /*  LED的COM有效电平选择      */
    uint8_t  LXD_LedSegLevel;               /*  LED的SEG有效电平选择      */
    uint8_t  LXD_LedBrightnessLevel;        /*  LED的亮度等级             */
    uint16_t LXD_LedDiv;                    /*  LED的显示分频             */
}LXD_LEDBaseInitTypeDef;


#define LXD_LcdFastChargeEnable              ((uint8_t)0x01)  
#define LXD_LcdFastChargeDisable             ((uint8_t)0x00)   
#define IS_LXD_FastCharge_EN(EN)             (((EN) == LXD_LcdFastChargeEnable) ||  \
                                             ((EN) == LXD_LcdFastChargeDisable))


#define LXD_LcdChargeTimeInside             ((uint8_t)0x00)
#define LXD_LcdChargeTime1us                ((uint8_t)0x02)
#define LXD_LcdChargeTime2us                ((uint8_t)0x04)
#define LXD_LcdChargeTime3us                ((uint8_t)0x06)
#define LXD_LcdChargeTime4us                ((uint8_t)0x08)
#define LXD_LcdChargeTime5us                ((uint8_t)0x0a)
#define LXD_LcdChargeTime6us                ((uint8_t)0x0c)
#define LXD_LcdChargeTime7us                ((uint8_t)0x0e) 
#define IS_LXD_ChargeTime_SEL(SEL)          (((SEL) == LXD_LcdChargeTimeInside) ||  \
                                            ((SEL) == LXD_LcdChargeTime1us)     ||  \
                                            ((SEL) == LXD_LcdChargeTime2us)     ||  \
                                            ((SEL) == LXD_LcdChargeTime3us)     ||  \
                                            ((SEL) == LXD_LcdChargeTime4us)     ||  \
                                            ((SEL) == LXD_LcdChargeTime5us)     ||  \
                                            ((SEL) == LXD_LcdChargeTime6us)     ||  \
                                            ((SEL) == LXD_LcdChargeTime7us))

#define LXD_LcdCurrentLevel2_5ua            ((uint8_t)0x00)
#define LXD_LcdCurrentLevel5ua              ((uint8_t)0x01)
#define LXD_LcdCurrentLevel20ua             ((uint8_t)0x02)
#define LXD_LcdCurrentLevel40ua             ((uint8_t)0x03)
#define LXD_LcdCurrentLevel80ua             ((uint8_t)0x04)
#define LXD_LcdCurrentLevel120ua            ((uint8_t)0x05)
#define IS_LXD_CurrentLevel_SEL(SEL)        (((SEL) == LXD_LcdCurrentLevel2_5ua)   ||  \
                                            ((SEL) == LXD_LcdCurrentLevel5ua)      ||  \
                                            ((SEL) == LXD_LcdCurrentLevel20ua)     ||  \
                                            ((SEL) == LXD_LcdCurrentLevel40ua)     ||  \
                                            ((SEL) == LXD_LcdCurrentLevel80ua)     ||  \
                                            ((SEL) == LXD_LcdCurrentLevel120ua))

#define LXD_LcdBias1_2                      ((uint8_t)0x01)
#define LXD_LcdBias1_3                      ((uint8_t)0x02)
#define LXD_LcdBias1_4                      ((uint8_t)0x03)
#define IS_LXD_LcdBias_SEL(SEL)             (((SEL) == LXD_LcdBias1_2)   ||  \
                                            ((SEL) == LXD_LcdBias1_3)    ||  \
                                            ((SEL) == LXD_LcdBias1_4))



#define LXD_LcdBrightnessLevel1             ((uint8_t)0x00)
#define LXD_LcdBrightnessLevel2             ((uint8_t)0x01)
#define LXD_LcdBrightnessLevel3             ((uint8_t)0x02)
#define LXD_LcdBrightnessLevel4             ((uint8_t)0x03)
#define LXD_LcdBrightnessLevel5             ((uint8_t)0x04)
#define LXD_LcdBrightnessLevel6             ((uint8_t)0x05)
#define LXD_LcdBrightnessLevel7             ((uint8_t)0x06)
#define LXD_LcdBrightnessLevel8             ((uint8_t)0x07)
#define IS_LXD_BrightnessLevel_SEL(SEL)     (((SEL) == LXD_LcdBrightnessLevel1)    ||  \
                                            ((SEL) == LXD_LcdBrightnessLevel2)     ||  \
                                            ((SEL) == LXD_LcdBrightnessLevel3)     ||  \
                                            ((SEL) == LXD_LcdBrightnessLevel4)     ||  \
                                            ((SEL) == LXD_LcdBrightnessLevel5)     ||  \
                                            ((SEL) == LXD_LcdBrightnessLevel6)     ||  \
                                            ((SEL) == LXD_LcdBrightnessLevel6)     ||  \
                                            ((SEL) == LXD_LcdBrightnessLevel8))


#define LXD_LedComLevelSelHigh              ((uint8_t)0x01)
#define LXD_LedComLevelSelLow               ((uint8_t)(~0x01))
#define IS_LXD_LedComLevel_SEL(SEL)         (((SEL) == LXD_LedComLevelSelHigh) ||  \
                                            ((SEL) == LXD_LedComLevelSelLow))

#define LXD_LedSegLevelSelHigh              ((uint8_t)0x01)
#define LXD_LedSegLevelSelLow               ((uint8_t)(~0x01))
#define IS_LXD_LedSegLevel_SEL(SEL)         (((SEL) == LXD_LedSegLevelSelHigh) ||  \
                                            ((SEL) == LXD_LedSegLevelSelLow))

#define LXD_LedBrightnessLevel1             ((uint8_t)0x00)
#define LXD_LedBrightnessLevel2             ((uint8_t)0x01)
#define LXD_LedBrightnessLevel3             ((uint8_t)0x02)
#define LXD_LedBrightnessLevel4             ((uint8_t)0x03)
#define LXD_LedBrightnessLevel5             ((uint8_t)0x04)
#define LXD_LedBrightnessLevel6             ((uint8_t)0x05)
#define LXD_LedBrightnessLevel7             ((uint8_t)0x06)
#define LXD_LedBrightnessLevel8             ((uint8_t)0x07)
#define IS_LXD_LEDBrightnessLevel_SEL(SEL)  (((SEL) == LXD_LedBrightnessLevel1)    ||  \
                                            ((SEL) == LXD_LedBrightnessLevel2)     ||  \
                                            ((SEL) == LXD_LedBrightnessLevel3)     ||  \
                                            ((SEL) == LXD_LedBrightnessLevel5)     ||  \
                                            ((SEL) == LXD_LedBrightnessLevel5)     ||  \
                                            ((SEL) == LXD_LedBrightnessLevel6)     ||  \
                                            ((SEL) == LXD_LedBrightnessLevel7)     ||  \
                                            ((SEL) == LXD_LedBrightnessLevel8))

#define LXD_LCD_MODE                        ((uint8_t)0x00)
#define LXD_LED_MODE                        ((uint8_t)0x01)
void LXD_LcdOrLedComIoSel(uint8_t comsel);
void LXD_LcdOrLedSeg0IoSel(uint32_t seg0sel);
void LXD_LCDBaseInit(LXD_LCDBaseInitTypeDef* LXD_LCDBaseStructure);
void LXD_LEDBaseInit(LXD_LEDBaseInitTypeDef* LXD_LEDBaseStructure);
void LXD_Cmd(uint8_t LXD_LXDMODE, FunctionalState NewState);
#endif

