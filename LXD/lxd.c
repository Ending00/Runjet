/**
  ******************************************************************************
  * @file    LXD.c
	* @author  
	* @Version V1.0.0
  * @Date    2023-8-6
  * @brief   LXD  function
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/

#include "lxd.h"
#include "rjm32l030_conf.h"
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void LXD_Config(uint16 psc)
{
  LXD_LCDBaseInitTypeDef  LXD_LCDBaseStructure;
  LXD_LEDBaseInitTypeDef  LXD_LEDBaseStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_LCD ,ENABLE); 

  LXD_LcdOrLedComIoSel(0x0F);       //Com03
  LXD_LcdOrLedSeg0IoSel(0x0000000F);//SEG03

  /*LCD*/
  LXD_LCDBaseStructure.LXD_LcdFastChargeState = LXD_LcdFastChargeEnable;
  LXD_LCDBaseStructure.LXD_LcdChargeTime = LXD_LcdChargeTime7us;
  LXD_LCDBaseStructure.LXD_LcdCurrentLevel = LXD_LcdCurrentLevel120ua;
  LXD_LCDBaseStructure.LXD_LcdBias = LXD_LcdBias1_3;  
  LXD_LCDBaseStructure.LXD_LcdBrightnessLevel = LXD_LcdBrightnessLevel8;
  LXD_LCDBaseStructure.LXD_LcdDiv = psc;  
  LXD_LCDBaseInit(&LXD_LCDBaseStructure);
  LXD_Cmd(LXD_LCD_MODE,ENABLE);
  /*LED*/
  LXD_LEDBaseStructure.LXD_LedComLevel = LXD_LedComLevelSelHigh;
  LXD_LEDBaseStructure.LXD_LedSegLevel = LXD_LedSegLevelSelHigh;
  LXD_LEDBaseStructure.LXD_LedBrightnessLevel = LXD_LedBrightnessLevel8;
  LXD_LEDBaseStructure.LXD_LedDiv = psc;
  LXD_LEDBaseInit(&LXD_LEDBaseStructure);
  LXD_Cmd(LXD_LED_MODE,ENABLE);
}

/**@brief LCD数码管显示编码表定义 */ 
static const uint8_t CodeTable1[][2] = \
{
	{  0x07, 0x0D}, /* 0 	*/
	{  0x06, 0x00}, /* 1 	*/
	{  0x03, 0x0E}, /* 2 	*/
	{  0x07, 0x0A}, /* 3 	*/
	{  0x06, 0x03}, /* 4 	*/
	{  0x05, 0x0B}, /* 5 	*/
	{  0x05, 0x0F}, /* 6 	*/
	{  0x07, 0x00}, /* 7 	*/
	{  0x07, 0x0F}, /* 8 	*/
	{  0x07, 0x0B}, /* 9 	*/
};

uint16_t adc_data = 0;
uint8_t DRam[4],C = 0;
void LCD_Test(void)
{
    for(C=0;C<0x0B;C++)
    {
       	DRam[0] = CodeTable1[C][0];
        DRam[1] = CodeTable1[C][1]; 
       	DRam[2] = CodeTable1[C][0];
        DRam[3] = CodeTable1[C][1]; 
        LXD->LXD_DATA.DAT8_Buf[0] = DRam[0];
        LXD->LXD_DATA.DAT8_Buf[1] = DRam[1];
        LXD->LXD_DATA.DAT8_Buf[2] = DRam[2];
        LXD->LXD_DATA.DAT8_Buf[3] = DRam[3];
        Delay_ms(1000);
    }   
}

