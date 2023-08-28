#ifndef __RJM32L030_LPTIM_H
#define __RJM32L030_LPTIM_H
#include "rjm32l030.h"

typedef struct 
{
    uint32_t LPTIM_CLKSRC_SEL;         /**/
    uint16_t LPTIM_Period;            /**/   
    uint8_t LPTIM_WAKEUP_EN;          /**/
    uint8_t LPTIM_INT_EN;             /**/
    uint8_t LPTIM_S0P_SEL;            /**/
    uint8_t LPTIM_EDGE_SEL;          /**/   
    uint8_t LPTIM_CT0_EN;          /**/

}LPTIM_TimeBaseInitTypeDef;

#define LPTIM_IT_TF0_IE                       ((uint8_t)0x80) 



#define LPTIM_CLKSRC_SEL_LSI                  ((uint32_t)0x00000)  
#define LPTIM_CLKSRC_SEL_LSE                  ((uint32_t)0x40000)  
#define IS_LPTIM_CLKSRC_SEL(CLKSRC)           (((CLKSRC) == TIM_CLKSRC_SEL_LSI) ||  \
                                              ((CLKSRC) == TIM_CLKSRC_SEL_LSE))

// #define LPTIM_Falling_Edge                   ((uint16_t)0x0000)
// #define LPTIM_Both_Edge                      ((uint16_t)0x0002)
// #define IS_LPTIM_S0P_SEL(S0P)                (((S0P) == LPTIM_Falling_Edge) ||  \
//                                              ((S0P) == LPTIM_Both_Edge))

// #define LPTIM_EDGE_REM                       ((uint16_t)0x0000)  
// #define LPTIM_EDGE_NOT                       ((uint16_t)0x0040)  
// #define IS_LPTIM_EDGE_SEL(EDGE)              (((EDGE) == LPTIM_EDGE_REM) ||  \
//                                              ((EDGE) == LPTIM_EDGE_NOT))


ITStatus LPTIME_GetFlagStatus(uint8_t TIM_IT);
void LPTIM_ClearITPendingBit(uint8_t TIM_IT);
void LPTIM_Cmd(FunctionalState NewState);
void LPTIM_TimeBaseInit(LPTIM_TimeBaseInitTypeDef* LPTIM_TimeBaseInitStruct);
#endif

