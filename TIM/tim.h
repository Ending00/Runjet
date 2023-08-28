#ifndef __TIM_H
#define __TIM_H

#include "rjm32l030.h"

void TIM_CallBack_Fun(TIMER_Type *TIMx);
void TIM_Test(u16 psc,u16 arr);
void TIM_PWM_Init(u16 psc,u16 arr);
void TIM_CAP_Init(u16 psc,u16 arr);
void Test_Fun(void);
void BKControl_Task(uint16 psc,uint16 arr,uint16 duty);
void Count_Task(uint16 psc,uint16 arr);
#endif
