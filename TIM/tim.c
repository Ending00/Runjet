/**
  ******************************************************************************
  * @file    TIM.c
	* @author  
	* @Version V1.0.0
  * @Date    2023-8-6
  * @brief   TIM  function
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/

#include "tim.h"
#include "rjm32l030_conf.h"
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void TIM_Test(u16 psc,u16 arr)  //定时中断
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	RCC_APBPeriphClockCmd(RCC_APBPeriph_TIMER0_EN,ENABLE);	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_IOCFG|RCC_APB1Periph_GPIOA|RCC_APB1Periph_GPIOB|RCC_APB1Periph_GPIOC|RCC_APB1Periph_GPIOH,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 // 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
	GPIO_Init(GPIOA, &GPIO_InitStructure);		
	
	TIM_TimeBaseStructure.TIM_Period = (arr-1) ;
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1);;
	TIM_TimeBaseStructure.TIM_CNT_DIR = TIM_CNT_DIR_Up;
	TIM_TimeBaseStructure.TIM_ARPE_EN = ENABLE;
	TIM_TimeBaseStructure.TIM_CLKSRC_SEL = TIM_CLKSRC_SEL_EX0;
	TIM_TimeBaseInit(TIMER0, &TIM_TimeBaseStructure);

	TIM_ITConfig(TIMER0,TIM_IT_UPOV_IE,ENABLE);
	TIM_Cmd(TIMER0, ENABLE);//使能TIMx
	
	NVIC_EnableIRQ(TIMER0_IRQn);	
}

void TIM_PWM_Init(u16 psc,u16 arr)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APBPeriphClockCmd(RCC_APBPeriph_TIMER3_EN,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_IOCFG|RCC_APB1Periph_GPIOA|RCC_APB1Periph_GPIOB|RCC_APB1Periph_GPIOC|RCC_APB1Periph_GPIOH,ENABLE);
    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 // 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
    GPIO_Init(GPIOA, &GPIO_InitStructure);					 //    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				 //
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
    GPIO_Init(GPIOA, &GPIO_InitStructure);	
    IOCFG->IOCFG_CTRLA |=  Bit0_En;              //PA0 -> TIM3_CH0
	IOCFG->IOCFG_CTRLA |=  Bit8_En;
	//初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = (arr-1) ;
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1);;
	TIM_TimeBaseStructure.TIM_CNT_DIR = TIM_CNT_DIR_Up;
	TIM_TimeBaseStructure.TIM_ARPE_EN = ENABLE;     //重载使能
	TIM_TimeBaseStructure.TIM_RELOAD_MODE = TIM_Reload_Mode0; //外部溢出重载
	TIM_TimeBaseStructure.TIM_ALIGN_MODE = TIM_ALIGN_MODE_Edge;//边沿对齐模式
	TIM_TimeBaseStructure.TIM_CLKSRC_SEL = TIM_CLKSRC_SEL_IN;
	TIM_TimeBaseInit(TIMER3, &TIM_TimeBaseStructure);	

	//初始化TIM3 CC0 PWM模式	
	TIM_OCInitStructure.TIM_OCMode =  TIM_OCMode_PWM1;	
	TIM_OCInitStructure.TIM_MOE_EN = ENABLE;          //主输出使能
	TIM_OCInitStructure.TIM_CMP_PRELOAD_EN = ENABLE;  //比较预装载使能
    TIM_OCInitStructure.TIM_CMP_EN = ENABLE;          //比较使能
	TIM_OCInitStructure.TIM_DT_EN = ENABLE;           //死区使能
	TIM_OCInitStructure.TIM_DEAD_TIME = 3;            //死区时间1us
	// TIM_OCInitStructure.TIM_Pulse = 40;               //占空比
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//输出极性	
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //互补比较输出使能
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High; 	//互补输出极性
	TIM_OC0Init(TIMER3, &TIM_OCInitStructure);
	
	// TIM_ITConfig(TIMER3,TIM_IT_CC0_CMP_IE | TIM_IT_CC0_CAP_IE,ENABLE);
	TIM_Cmd(TIMER3, ENABLE);//使能TIMx

	// NVIC_EnableIRQ(TIMER3_IRQn);
}

void TIM_CAP_Init(u16 psc,u16 arr)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_ICInitTypeDef  TIM_ICInitStructure;

	RCC_APBPeriphClockCmd(RCC_APBPeriph_TIMER3_EN,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_IOCFG|RCC_APB1Periph_GPIOA|RCC_APB1Periph_GPIOB|RCC_APB1Periph_GPIOC|RCC_APB1Periph_GPIOH,ENABLE);

	IOCFG->IOCFG_CTRLB |= (Bit4_En|Bit5_En);	//PB2 -> TIM3_CAP0
	//初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = (arr-1) ;
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1);;
	TIM_TimeBaseStructure.TIM_CNT_DIR = TIM_CNT_DIR_Up;
	TIM_TimeBaseStructure.TIM_ARPE_EN = ENABLE;     //重载使能
	TIM_TimeBaseStructure.TIM_RELOAD_MODE = TIM_Reload_Mode0; //外部溢出重载
	TIM_TimeBaseStructure.TIM_ALIGN_MODE = TIM_ALIGN_MODE_Edge;//边沿对齐模式
	TIM_TimeBaseStructure.TIM_CLKSRC_SEL = TIM_CLKSRC_SEL_IN;
	TIM_TimeBaseInit(TIMER3, &TIM_TimeBaseStructure);	

	TIM_ICInitStructure.TIM_Channel = TIM_Channel_0;
  	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
  	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectCCx; //映射到CAP0上
	TIM_ICInitStructure.TIM_ICFilterCP = TIM_ICPSC_CP2;
	TIM_ICInit(TIMER3, &TIM_ICInitStructure);

	TIM_ITConfig(TIMER3,TIM_IT_CC0_CAP_IE | TIM_IT_UPDATE_IE,ENABLE);
	TIM_Cmd(TIMER3, ENABLE);//使能TIMx
	
	NVIC_EnableIRQ(TIMER3_IRQn);	
}

uint8_t  TIM3CCC0_CAPTURE_STA=0;	//输入捕获状态
uint32_t	TIM3CCC0_CAPTURE_VAL;	//输入捕获值
// void TIM_CallBack_Fun(TIMER_Type *TIMx)
// {
// 	if((TIM3CCC0_CAPTURE_STA&0X80)==0)//还未成功捕获
// 	{
// 		if (TIM_GetITStatus(TIMER3, TIM_IT_UPDATE_IE) != RESET) //溢出更新
// 		{
// 			if(TIM3CCC0_CAPTURE_STA&0X40)//已经捕获到高电平了
// 			{
//                 if((TIM3CCC0_CAPTURE_STA&0X3F)==0X3F)//高电平太长了
//                 {
//                     TIM3CCC0_CAPTURE_STA|=0X80;//标记成功捕获了一次
//                     TIM3CCC0_CAPTURE_VAL=0XFFFF;
//                 }else TIM3CCC0_CAPTURE_STA++; 				
// 			}
// 		}
// 		if (TIM_GetITStatus(TIMER3, TIM_IT_CC0_CAP_IE) != RESET) //CC0发生捕获事件
// 		{
//             if(TIM3CCC0_CAPTURE_STA&0X40)		//捕获到一个下降沿 		
//             {	  			
//                 TIM3CCC0_CAPTURE_STA|=0X80;		//标记成功捕获到一次高电平脉宽
//                 TIM3CCC0_CAPTURE_VAL=TIM_GetCapture0(TIMER3);	//获取当前的捕获值.
				// TIM_OC0PolarityConfig(TIMER3,TIM_ICPolarity_Rising);
//             }else  								//还未开始,第一次捕获上升沿
//             {
//                 TIM3CCC0_CAPTURE_STA=0;			//清空
//                 TIM3CCC0_CAPTURE_VAL=0;
// 				TIM_SetCounter(TIMER3,0);		//计数器清空
//                 TIM3CCC0_CAPTURE_STA|=0X40;		//标记捕获到了上升沿
// 				TIM_OC0PolarityConfig(TIMER3,TIM_ICPolarity_Falling);
//             }	  			
// 		}
// 	}
// 	TIM_ClearITPendingBit(TIMER3, TIM_IT_CC0_CAP_IE | TIM_IT_UPDATE_IE);
// }
void Test_Fun(void)
{
	uint32_t temp=0;
	while(1)
	{
		if(TIM3CCC0_CAPTURE_STA&0X80)//成功捕获到了一次上升沿
		{
			temp=TIM3CCC0_CAPTURE_STA&0X3F;
			temp*=65536;//溢出时间总和
			temp+=TIM3CCC0_CAPTURE_VAL;//得到总的高电平时间
			printf("HIGH:%d us\r\n",temp);//打印总的高点平时间
			TIM3CCC0_CAPTURE_STA=0;//开启下一次捕获
		}		
	}
}


void BKControl_Task(uint16 psc,uint16 arr,uint16 duty)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APBPeriphClockCmd(RCC_APBPeriph_TIMER3_EN,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_IOCFG|RCC_APB1Periph_GPIOA|RCC_APB1Periph_GPIOB|RCC_APB1Periph_GPIOC|RCC_APB1Periph_GPIOH,ENABLE);
    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 // 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
    GPIO_Init(GPIOA, &GPIO_InitStructure);					 //    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				 //
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
    GPIO_Init(GPIOA, &GPIO_InitStructure);	
    IOCFG->IOCFG_CTRLA |=  Bit0_En;              //PA0 -> TIM3_CH0
	IOCFG->IOCFG_CTRLA |=  Bit8_En;
	IOCFG->IOCFG_CTRLA |=  Bit15_En;             //PA6 -> TIM3_BKIN
	IOCFG->IOCFG_CTRLO |= Bit22_En;   //PA6输入使能
//		IOCFG->IOCFG_CTRLE |= Bit22_En;   //PA6上拉使能
	IOCFG->IOCFG_CTRLF |= Bit22_En;   //PA6下拉使能


	//初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = (arr-1) ;
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1);;
	TIM_TimeBaseStructure.TIM_CNT_DIR = TIM_CNT_DIR_Up;
	TIM_TimeBaseStructure.TIM_ARPE_EN = ENABLE;     //重载使能
	TIM_TimeBaseStructure.TIM_RELOAD_MODE = TIM_Reload_Mode0; //外部溢出重载
	TIM_TimeBaseStructure.TIM_ALIGN_MODE = TIM_ALIGN_MODE_Edge;//边沿对齐模式
	TIM_TimeBaseStructure.TIM_CLKSRC_SEL = TIM_CLKSRC_SEL_IN;
	TIM_TimeBaseInit(TIMER3, &TIM_TimeBaseStructure);

	//初始化TIM3 CC0 PWM模式	
	TIM_OCInitStructure.TIM_OCMode =  TIM_OCMode_PWM1;	
	TIM_OCInitStructure.TIM_MOE_EN = ENABLE;          //主输出使能
	TIM_OCInitStructure.TIM_CMP_PRELOAD_EN = ENABLE;  //比较预装载使能
    TIM_OCInitStructure.TIM_CMP_EN = ENABLE;          //比较使能
	TIM_OCInitStructure.TIM_DT_EN = ENABLE;           //死区使能
	TIM_OCInitStructure.TIM_DEAD_TIME = 3;            //死区时间3us
	TIM_OCInitStructure.TIM_Pulse = duty;               //占空比
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//输出极性	
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //互补比较输出使能
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High; 	//互补输出极性
	TIM_OCInitStructure.TIM_BreakIdleState = TIM_BKIdleState_Set;
	TIM_OCInitStructure.TIM_BreakNIdleState = TIM_BKNIdleState_Reset;	
	TIM_OC0Init(TIMER3, &TIM_OCInitStructure);

	TIM_BDTRInitStructure.TIM_AutoOutput = TIM_AutoOutput_Disable;  //自输出使能
	TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;	
	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
	TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;	
	TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Disable;
	TIM_BDTRInitStructure.TIM_BreakFilter = TIM_ICPSC_CP255;
	TIM_BDTRInitStructure.TIM_ExtBreak = TIM_ExtBreak_Enable;
	TIM_BDTRInitStructure.TIM_CompBreak = TIM_CompBreak_Disable;
	TIM_BDTRInitStructure.TIM_CompBreakSel = TIM_CompBreakSel_Comp1;
	TIM_BDTRConfig(TIMER3, &TIM_BDTRInitStructure);

	TIM_ITConfig(TIMER3,TIM_IT_BK_RISE_IE,ENABLE);

	TIM_Cmd(TIMER3, ENABLE);//使能TIMx
	
	NVIC_EnableIRQ(TIMER3_IRQn);
}

void Count_Task(uint16 psc,uint16 arr)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_ICInitTypeDef  TIM_ICInitStructure;
	RCC_APBPeriphClockCmd(RCC_APBPeriph_TIMER0_EN,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_GPIOA | RCC_APB1Periph_GPIOB |  RCC_APB1Periph_GPIOC |   RCC_APB1Periph_GPIOH | RCC_APB1Periph_IOCFG,ENABLE); 

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
    GPIO_Init(GPIOA, &GPIO_InitStructure);					 //
    IOCFG->IOCFG_CTRLC |=  Bit9_En;              //PC4 -> TIM0_TFF
	//初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = (arr-1) ;
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1);;
	TIM_TimeBaseStructure.TIM_CNT_DIR = TIM_CNT_DIR_Up;
	TIM_TimeBaseStructure.TIM_ARPE_EN = ENABLE;     //重载使能
//	TIM_TimeBaseStructure.TIM_RELOAD_MODE = TIM_Reload_Mode0; //外部溢出重载
//	TIM_TimeBaseStructure.TIM_ALIGN_MODE = TIM_ALIGN_MODE_Edge;//边沿对齐模式
	TIM_TimeBaseStructure.TIM_CLKSRC_SEL = TIM_CLKSRC_SEL_EX1; //外部时钟模式1
	// TIM_TimeBaseStructure.TIM_T2EXM_EN =  DISABLE;             //默认复用为T2FF
	TIM_TimeBaseInit(TIMER0, &TIM_TimeBaseStructure);
	
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_0;
  	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
	TIM_ICInit(TIMER0, &TIM_ICInitStructure);
	
    // TIM_SelectInputTrigger(TIMER3, TIM_TS_T2FF); 

	TIM_ITConfig(TIMER0,TIM_IT_UPOV_IE,ENABLE);
	TIM_Cmd(TIMER0, ENABLE);//使能TIMx

    NVIC_EnableIRQ(TIMER0_IRQn);
}






void TIM_CallBack_Fun(TIMER_Type *TIMx)
{
	if (TIM_GetITStatus(TIMER0, TIM_IT_UPOV_IE) != RESET)
	{
		GPIO_ReversalBits(GPIOA,GPIO_Pin_7);
		TIM_ClearITPendingBit(TIMER0, TIM_IT_UPOV_IE);
		
	}
	if (TIM_GetITStatus(TIMER3, TIM_IT_CC0_CMP_IE) != RESET)
	{
		TIM_ClearITPendingBit(TIMER3, TIM_IT_CC0_CMP_IE);
		
	}
	if (TIM_GetITStatus(TIMER3, TIM_IT_CC0_CAP_IE) != RESET)
	{
		TIM_ClearITPendingBit(TIMER3, TIM_IT_CC0_CAP_IE);	
	}

	if (TIM_GetITStatus(TIMER3, TIM_IT_BK_RISE_IE | TIM_IT_BK_FALL_IE) != RESET)
	{
		TIM_ClearITPendingBit(TIMER3, TIM_IT_BK_RISE_IE | TIM_IT_BK_FALL_IE);	
	}
}
