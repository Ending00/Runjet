#ifndef __RJM32L030_TIM_H
#define __RJM32L030_TIM_H
#include "rjm32l030.h"

typedef struct 
{
    uint8_t TIM_T2EXM_EN;           /**/
    uint8_t TIM_REPEAT_EN;          /**/
    uint8_t TIM_OPM_EN;             /**/
    uint8_t TIM_ARPE_EN;            /**/

    uint8_t TIM_UDIS_EN;            /**/
    uint16_t TIM_TFFEDGE_SEL;       /**/
    uint8_t TIM_RELOAD_MODE;        /**/
    uint16_t TIM_CNT_DIR;           /**/

    uint8_t TIM_ALIGN_MODE;         /**/
    uint8_t TIM_CLKSRC_SEL;         /**/
    uint16_t TIM_Prescaler;         /**/
    uint16_t TIM_Period;            /**/
    uint8_t TIM_RepetitionCounter;  /**/ 
}TIM_TimeBaseInitTypeDef;

typedef struct 
{
    uint16_t TIM_CMPMode;
    uint16_t TIM_OCMode;            /*模式*/
    uint16_t TIM_MOE_EN;            /*主输出使能*/
    uint16_t TIM_CMP_PRELOAD_EN;    /*比较值预装载使能*/
    uint16_t TIM_CMP_EN;            /*比较使能*/
    uint16_t TIM_DT_EN;             /*死区使能*/
    uint16_t TIM_OutputState;       /*比较输出使能*/
    uint16_t TIM_OutputNState;      /*比较互补输出使能*/  
    uint16_t TIM_Pulse;  
    uint8_t  TIM_DEAD_TIME;  
    uint16_t TIM_OCPolarity;        /*比较输出极性*/
    uint16_t TIM_OCNPolarity;       /*比较互补输出极性*/
    // uint16_t TIM_OCIdleState;       /*比较输出空闲极性*/
    // uint16_t TIM_OCNIdleState;      /*比较互补输出空闲极性*/
    uint16_t TIM_BreakIdleState;    /*刹车输出空闲极性*/
    uint16_t TIM_BreakNIdleState;   /*刹车输出空闲极性*/

}TIM_OCInitTypeDef;

/** 
  * @brief  TIM Input Capture Init structure definition  
  */
typedef struct
{
  uint16_t TIM_Channel;
  uint16_t TIM_ICPolarity; 
  uint16_t TIM_ICSelection;
  uint16_t TIM_ICFilterCP;    
} TIM_ICInitTypeDef;

/** 
  * @brief  BDTR structure definition 
  * @note   This structure is used only with TIM1 and TIM8.    
  */
typedef struct 
{
  uint16_t TIM_AutoOutput;     //自动输出使能
  uint16_t TIM_BreakPolarity;  //刹车输入极性
  uint16_t TIM_Break;          //刹车使能
  uint16_t TIM_OSSRState;      //运行模式
  uint16_t TIM_OSSIState;      //空闲模式
  uint16_t TIM_BreakFilter;    //刹车滤波
  uint16_t TIM_ExtBreak;       //外部刹车使能
  uint16_t TIM_CompBreak;      //比较器刹车使能
  uint16_t TIM_CompBreakSel;   //比较器输入选择
}TIM_BDTRInitTypeDef;

#define TIM_CLKSRC_SEL_IN                   ((uint16_t)0x0000)  /*TIM0\1\2 close tim || TIM3\4 Internal predivision clock*/
#define TIM_CLKSRC_SEL_EX0                  ((uint16_t)0x0001)  /*TIM0\1\2 Internal predivision clock || TIM3\4 External predivision clock*/
#define TIM_CLKSRC_SEL_EX1                  ((uint16_t)0x0002)  /*TIM0\1\2 External  clock 1 || TIM3\4 External  clock 1*/
#define TIM_CLKSRC_SEL_EX2                  ((uint16_t)0x0003)  /*TIM0\1\2 close tim || TIM3\4 External  clock 2*/
#define IS_TIM_CLKSRC_SEL(CLKSRC)           (((CLKSRC) == TIM_CLKSRC_SEL_IN) ||  \
                                            ((CLKSRC) == TIM_CLKSRC_SEL_EX0) ||  \
                                            ((CLKSRC) == TIM_CLKSRC_SEL_EX1) ||  \
                                            ((CLKSRC) == TIM_CLKSRC_SEL_EX2))

#define TIM_ALIGN_MODE_Edge                 ((uint16_t)0x0000)
#define TIM_ALIGN_MODE_Center               ((uint16_t)0x0004)
#define IS_TIM_ALIGN_MODE(MODE)             (((MODE) == TIM_ALIGN_MODE_Edge) ||  \
                                            ((MODE) == TIM_ALIGN_MODE_Center))

#define TIM_Reload_Forbid                  ((uint16_t)0x0000)
#define TIM_Reload_Mode0                   ((uint16_t)0x0080)
#define TIM_Reload_Mode1                   ((uint16_t)0x00C0)
#define IS_TIM_IC_RELOAD_MODE(MODE)        (((MODE) == TIM_Reload_Forbid) || \
                                           ((MODE) == TIM_Reload_Mode0)|| \
                                           ((MODE) == TIM_Reload_Mode1)) 

#define TIM_Falling_Edge                   ((uint16_t)0x0000)
#define TIM_Rising_Edge                    ((uint16_t)0x0100)
#define TIM_Both_Edge                      ((uint16_t)0x0200)
#define IS_TIM_IC_TFF_Edge(Edge)           (((Edge) == TIM_Falling_Edge) || \
                                           ((Edge) == TIM_Rising_Edge)|| \
                                           ((Edge) == TIM_Both_Edge)) 

#define TIM_CNT_DIR_Up                      ((uint16_t)0x0000)
#define TIM_CNT_DIR_Down                    ((uint16_t)0x0010)
#define IS_TIM_COUNTER_MODE(MODE)           (((MODE) == TIM_CNT_DIR_Up) ||  \
                                            ((MODE) == TIM_CNT_DIR_Down))

#define IS_TIM_ALL_PERIPH(PERIPH)           (((PERIPH) == TIM0) || \
                                            ((PERIPH) == TIM1) || \
                                            ((PERIPH) == TIM2) || \
                                            ((PERIPH) == TIM3) || \
                                            ((PERIPH) == TIM4))

#define IS_TIM_012_PERIPH(PERIPH)           (((PERIPH) == TIM0) || \
                                            ((PERIPH) == TIM1) || \
                                            ((PERIPH) == TIM2))

#define IS_TIM_34_PERIPH(PERIPH)           (((PERIPH) == TIM3) || \
                                            ((PERIPH) == TIM4))

/** @defgroup TIM_Output_Compare_and_PWM_modes 
  * @{
  */
#define TIM_OCMode_PWM1                    ((uint16_t)0x0000)
#define TIM_OCMode_PWM2                    ((uint16_t)0x0001)

#define TIM_CMPMode_CMP0                    ((uint16_t)0x0000)
#define TIM_CMPMode_CMP1                    ((uint16_t)0x0001)

#define IS_TIM_OC_MODE(MODE) (((MODE) == TIM_OCMode_PWM1) || \
                              ((MODE) == TIM_OCMode_PWM2)|| \
                              ((MODE) == TIM_CMPMode_CMP0) || \
                              ((MODE) == TIM_CMPMode_CMP1))

#define TIM_OCxID_High               ((uint16_t)0x0001)
#define TIM_OCxID_Low                ((uint16_t)0x0000)
#define IS_TIM_OCx_ID(ID)            (((ID) == TIM_OCxID_High) || \
                                     ((ID) == TIM_OCxID_Low))

/** @defgroup TIM_Output_Compare_Polarity 
  * @{
  */
#define TIM_OCPolarity_High                ((uint16_t)0x0000)
#define TIM_OCPolarity_Low                 ((uint16_t)0x0001)
#define IS_TIM_OC_POLARITY(POLARITY) (((POLARITY) == TIM_OCPolarity_High) || \
                                      ((POLARITY) == TIM_OCPolarity_Low))

/** @defgroup TIM_Output_Compare_N_Polarity 
  * @{
  */
#define TIM_OCNPolarity_High               ((uint16_t)0x0000)
#define TIM_OCNPolarity_Low                ((uint16_t)0x0001)
#define IS_TIM_OCN_POLARITY(POLARITY) (((POLARITY) == TIM_OCNPolarity_High) || \
                                       ((POLARITY) == TIM_OCNPolarity_Low))


/** @defgroup TIM_Output_Compare_state 
  * @{
  */
#define TIM_OutputState_Disable            ((uint16_t)0x0000)
#define TIM_OutputState_Enable             ((uint16_t)0x0001)
#define IS_TIM_OUTPUT_STATE(STATE) (((STATE) == TIM_OutputState_Disable) || \
                                    ((STATE) == TIM_OutputState_Enable))

/** @defgroup TIM_Output_Compare_N_state 
  * @{
  */
#define TIM_OutputNState_Disable           ((uint16_t)0x0000)
#define TIM_OutputNState_Enable            ((uint16_t)0x0001)
#define IS_TIM_OUTPUTN_STATE(STATE) (((STATE) == TIM_OutputNState_Disable) || \
                                     ((STATE) == TIM_OutputNState_Enable))

#define  TIM_CAP_CC0E                      ((uint32_t)0x10000000)  /*!< Capture/Compare 0 output enable */
#define  TIM_CAP_CC1E                      ((uint16_t)0x20000000)  /*!< Capture/Compare 1 output enable */
#define  TIM_CAP_CC2E                      ((uint16_t)0x40000000)  /*!< Capture/Compare 2 output enable */
#define  TIM_CAP_CC3E                      ((uint16_t)0x80000000)  /*!< Capture/Compare 3 output enable */
#define  TIM_CAP_CC0P                      ((uint32_t)0x0000000C)  /*!< Capture/Compare 0 output Polarity */
#define  TIM_CAP_CC1P                      ((uint16_t)0x00000C00)  /*!< Capture/Compare 1 output Polarity */
#define  TIM_CAP_CC2P                      ((uint16_t)0x000C0000)  /*!< Capture/Compare 2 output Polarity */
#define  TIM_CAP_CC3P                      ((uint16_t)0x0C000000)  /*!< Capture/Compare 3 output Polarity */
/** @defgroup TIM_Channel 
  * @{
  */

#define TIM_Channel_0                      ((uint16_t)0x0000)
#define TIM_Channel_1                      ((uint16_t)0x0004)
#define TIM_Channel_2                      ((uint16_t)0x0008)
#define TIM_Channel_3                      ((uint16_t)0x000C)
#define IS_TIM_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
                                 ((CHANNEL) == TIM_Channel_2) || \
                                 ((CHANNEL) == TIM_Channel_3) || \
                                 ((CHANNEL) == TIM_Channel_4))

/** @defgroup TIM_Input_Capture_Polarity 
  * @{
  */

#define  TIM_ICPolarity_Rising             ((uint16_t)0x0001)
#define  TIM_ICPolarity_Falling            ((uint16_t)0x0002)
#define  TIM_ICPolarity_BothEdge           ((uint16_t)0x0003)
#define IS_TIM_IC_POLARITY(POLARITY) (((POLARITY) == TIM_ICPolarity_Rising) || \
                                      ((POLARITY) == TIM_ICPolarity_Falling))
#define IS_TIM_IC_POLARITY_LITE(POLARITY) (((POLARITY) == TIM_ICPolarity_Rising) || \
                                           ((POLARITY) == TIM_ICPolarity_Falling)|| \
                                           ((POLARITY) == TIM_ICPolarity_BothEdge))   

/** @defgroup TIM_Input_Capture_Selection 
  * @{
  */

#define TIM_ICSelection_DirectCCx           ((uint16_t)0x0001)
#define TIM_ICSelection_IndirectCCx         ((uint16_t)0x0002)
#define TIM_ICSelection_DCB                 ((uint16_t)0x0003) 
#define IS_TIM_IC_SELECTION(SELECTION) (((SELECTION) == TIM_ICSelection_DirectTI) || \
                                        ((SELECTION) == TIM_ICSelection_IndirectTI) || \
                                        ((SELECTION) == TIM_ICSelection_TRC))

/** @defgroup TIM_Input_Capture_Prescaler 
  * @{
  */

#define TIM_ICPSC_CP2                     ((uint16_t)0x0001) /*!< Capture performed each time an edge is detected on the capture input. */
#define TIM_ICPSC_CP4                     ((uint16_t)0x0002) /*!< Capture performed once every 2 events. */
#define TIM_ICPSC_CP8                     ((uint16_t)0x0003) /*!< Capture performed once every 4 events. */
#define TIM_ICPSC_CP12                    ((uint16_t)0x0004) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP16                    ((uint16_t)0x0005) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP24                    ((uint16_t)0x0006) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP32                    ((uint16_t)0x0007) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP48                    ((uint16_t)0x0008) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP64                    ((uint16_t)0x0009) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP80                    ((uint16_t)0x000A) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP96                    ((uint16_t)0x000B) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP128                   ((uint16_t)0x000C) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP160                   ((uint16_t)0x000D) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP192                   ((uint16_t)0x000E) /*!< Capture performed once every 8 events. */
#define TIM_ICPSC_CP255                   ((uint16_t)0x000F) /*!< Capture performed once every 8 events. */
#define IS_TIM_IC_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ICPSC_CP2) || \
                                        ((PRESCALER) == TIM_ICPSC_CP4) || \
                                        ((PRESCALER) == TIM_ICPSC_CP8) || \
                                        ((PRESCALER) == TIM_ICPSC_CP12) || \
                                        ((PRESCALER) == TIM_ICPSC_CP16) || \
                                        ((PRESCALER) == TIM_ICPSC_CP24) || \
                                        ((PRESCALER) == TIM_ICPSC_CP32) || \
                                        ((PRESCALER) == TIM_ICPSC_CP48) || \
                                        ((PRESCALER) == TIM_ICPSC_CP64) || \
                                        ((PRESCALER) == TIM_ICPSC_CP80) || \
                                        ((PRESCALER) == TIM_ICPSC_CP96) || \
                                        ((PRESCALER) == TIM_ICPSC_CP128) || \
                                        ((PRESCALER) == TIM_ICPSC_CP160) || \
                                        ((PRESCALER) == TIM_ICPSC_CP192) || \
                                        ((PRESCALER) == TIM_ICPSC_CP255))


/** @defgroup Break_Input_enable_disable 
  * @{
  */
#define TIM_Break_Enable                   ((uint16_t)0x1000)
#define TIM_Break_Disable                  ((uint16_t)0x0000)
#define IS_TIM_BREAK_STATE(STATE) (((STATE) == TIM_Break_Enable) || \
                                   ((STATE) == TIM_Break_Disable))

 /** @defgroup EXTBreak_Input_enable_disable 
  * @{
  */
#define TIM_ExtBreak_Enable                   ((uint16_t)0x0004)
#define TIM_ExtBreak_Disable                  ((uint16_t)0x0000)
#define IS_TIM_EXTBREAK_STATE(STATE) (((STATE) == TIM_ExtBreak_Enable) || \
                                   ((STATE) == TIM_ExtBreak_Disable))

 /** @defgroup COMPBreak_Input_enable_disable 
  * @{
  */
#define TIM_CompBreak_Enable                   ((uint16_t)0x0002)
#define TIM_CompBreak_Disable                  ((uint16_t)0x0000)
#define IS_TIM_COMPBREAK_STATE(STATE) (((STATE) == TIM_CompBreak_Enable) || \
                                   ((STATE) == TIM_CompBreak_Disable))

 /** @defgroup TIM_CompBreakSel_comp1_comp2 
  * @{
  */
#define TIM_CompBreakSel_Comp2                   ((uint16_t)0x0001)
#define TIM_CompBreakSel_Comp1                   ((uint16_t)0x0000)
#define IS_TIM_COMPBREAK_SEL(SEL) (((SEL) == TIM_CompBreakSel_Comp2) || \
                                   ((SEL) == TIM_CompBreakSel_Comp1))

/** @defgroup Break_Polarity 
  * @{
  */
#define TIM_BreakPolarity_Low              ((uint16_t)0x0000)
#define TIM_BreakPolarity_High             ((uint16_t)0x2000)
#define IS_TIM_BREAK_POLARITY(POLARITY) (((POLARITY) == TIM_BreakPolarity_Low) || \
                                         ((POLARITY) == TIM_BreakPolarity_High))

/** @defgroup TIM_AOE_Bit_Set_Reset 
  * @{
  */
#define TIM_AutoOutput_Enable         ((uint16_t)0x4000)
#define TIM_AutoOutput_Disable        ((uint16_t)0x0000)
#define IS_TIM_AUTO_OUTPUT_STATE(STATE) (((STATE) == TIM_AutoOutput_Enable) || \
                                              ((STATE) == TIM_AutoOutput_Disable))

/** @defgroup OSSI_Off_State_Selection_for_Idle_mode_state 
  * @{
  */
#define TIM_OSSIState_Enable               ((uint16_t)0x0400)
#define TIM_OSSIState_Disable              ((uint16_t)0x0000)
#define IS_TIM_OSSI_STATE(STATE) (((STATE) == TIM_OSSIState_Enable) || \
                                  ((STATE) == TIM_OSSIState_Disable))

/** @defgroup OSSR_Off_State_Selection_for_Run_mode_state 
  * @{
  */
#define TIM_OSSRState_Enable               ((uint16_t)0x0800)
#define TIM_OSSRState_Disable              ((uint16_t)0x0000)
#define IS_TIM_OSSR_STATE(STATE) (((STATE) == TIM_OSSRState_Enable) || \
                                  ((STATE) == TIM_OSSRState_Disable))

/** @defgroup TIM_Output_Break_Idle_State 
  * @{
  */
#define TIM_BKIdleState_Set                ((uint16_t)0x0001)
#define TIM_BKIdleState_Reset              ((uint16_t)0x0000)
#define IS_TIM_BKIDLE_STATE(STATE) (((STATE) == TIM_BKIdleState_Set) || \
                                    ((STATE) == TIM_BKIdleState_Reset))

/** @defgroup TIM_Output_BreakN_Idle_State 
  * @{
  */
#define TIM_BKNIdleState_Set                ((uint16_t)0x0001)
#define TIM_BKNIdleState_Reset              ((uint16_t)0x0000)
#define IS_TIM_BKNIDLE_STATE(STATE) (((STATE) == TIM_BKNIdleState_Set) || \
                                    ((STATE) == TIM_BKNIdleState_Reset))

/** @defgroup TIM_DMA_sources 
  * @{
  */
#define TIM_DMA_Trigger                    ((uint32_t)0x200000)
#define TIM_DMA_Update                     ((uint32_t)0x100000)
#define TIM_DMA_CC3                        ((uint32_t)0x080000)
#define TIM_DMA_CC2                        ((uint32_t)0x040000)
#define TIM_DMA_CC1                        ((uint32_t)0x020000)
#define TIM_DMA_CC0                        ((uint32_t)0x010000)

/** @defgroup TIM_interrupt_sources 
  * @{
  */
#define TIM_IT_TRG_DE                      ((uint32_t)0x200000)
#define TIM_IT_UPDATE_DE                   ((uint32_t)0x100000)

#define TIM_IT_TRG_FLAG                    ((uint32_t)0x100000)

#define TIM_IT_CC3_DE                      ((uint32_t)0x080000)
#define TIM_IT_CC2_DE                      ((uint32_t)0x040000)
#define TIM_IT_CC1_DE                      ((uint32_t)0x020000)
#define TIM_IT_CC0_DE                      ((uint32_t)0x010000)
#define TIM_IT_TRG_IE                      ((uint16_t)0x8000)

#define TIM_IT_BK_MARK                     ((uint16_t)0x8000)

#define TIM_IT_BK_RISE_IE                  ((uint16_t)0x4000)
#define TIM_IT_BK_FALL_IE                  ((uint16_t)0x2000)
#define TIM_IT_EXRELOAD_IE                 ((uint16_t)0x1000)
#define TIM_IT_UPOV_IE                     ((uint16_t)0x0800)
#define TIM_IT_DOWNOV_IE                   ((uint16_t)0x0400)
#define TIM_IT_UPDATE_IE                   ((uint16_t)0x0100)
#define TIM_IT_CC3_CMP_IE                  ((uint16_t)0x0080)
#define TIM_IT_CC2_CMP_IE                  ((uint16_t)0x0040)
#define TIM_IT_CC1_CMP_IE                  ((uint16_t)0x0020)
#define TIM_IT_CC0_CMP_IE                  ((uint16_t)0x0010)
#define TIM_IT_CC3_CAP_IE                  ((uint16_t)0x0008)
#define TIM_IT_CC2_CAP_IE                  ((uint16_t)0x0004)
#define TIM_IT_CC1_CAP_IE                  ((uint16_t)0x0002)
#define TIM_IT_CC0_CAP_IE                  ((uint16_t)0x0001)

#define IS_TIM_IT(IT) ((((IT) & (uint32_t)0xFF000000) == 0x00000000) && ((IT) != 0x00000000))

#define IS_TIM_GET_IT(IT) (((IT) == TIM_IT_CC0_CAP_IE) || \
                           ((IT) == TIM_IT_CC1_CAP_IE) || \
                           ((IT) == TIM_IT_CC2_CAP_IE) || \
                           ((IT) == TIM_IT_CC3_CAP_IE) || \
                           ((IT) == TIM_IT_CC0_CMP_IE) || \
                           ((IT) == TIM_IT_CC1_CMP_IE) || \
                           ((IT) == TIM_IT_CC2_CMP_IE) || \
                           ((IT) == TIM_IT_CC3_CMP_IE) || \
                           ((IT) == TIM_IT_UPDATE_IE)  || \
                           ((IT) == TIM_IT_DOWNOV_IE)  || \
                           ((IT) == TIM_IT_UPOV_IE)    || \
                           ((IT) == TIM_IT_EXRELOAD_IE)|| \
                           ((IT) == TIM_IT_BK_FALL_IE) || \
                           ((IT) == TIM_IT_BK_RISE_IE))

/** @defgroup TIM_Slave_Mode 
  * @{
  */
#define TIM_SlaveMode_Reset                ((uint16_t)0x0004)
#define TIM_SlaveMode_Gated                ((uint16_t)0x0005)
#define TIM_SlaveMode_Trigger              ((uint16_t)0x0006)
#define TIM_SlaveMode_Reserve              ((uint16_t)0x0007)
#define IS_TIM_SLAVE_MODE(MODE) (((MODE) == TIM_SlaveMode_Reset) || \
                                 ((MODE) == TIM_SlaveMode_Gated) || \
                                 ((MODE) == TIM_SlaveMode_Trigger) || \
                                 ((MODE) == TIM_SlaveMode_Reserve))

/** @defgroup TIM_Trigger_Output_Source 
  * @{
  */
#define TIM_TRG3_EN              ((uint16_t)0x8000)
#define TIM_TRG2_EN              ((uint16_t)0x4000)
#define TIM_TRG1_EN              ((uint16_t)0x2000)
#define TIM_TRG0_EN              ((uint16_t)0x1000)
#define IS_TIM_TRGO_SOURCE(SOURCE) (((SOURCE) == TIM_TRG3_EN) || \
                                    ((SOURCE) == TIM_TRG2_EN) || \
                                    ((SOURCE) == TIM_TRG1_EN) || \
                                    ((SOURCE) == TIM_TRG0_EN))

/** @defgroup TIM_One_Pulse_Mode 
  * @{
  */
#define TIM_OPMode_Single                  ((uint16_t)0x4000)
#define TIM_OPMode_Repetitive              ((uint16_t)0x0000)
#define IS_TIM_OPM_MODE(MODE) (((MODE) == TIM_OPMode_Single) || \
                               ((MODE) == TIM_OPMode_Repetitive))

/** @defgroup TIM_Internal_Trigger_Selection 
  * @{
  */
#define TIM_TS_CC0F_RF                        ((uint16_t)0x0040)
#define TIM_TS_CC0FP0                         ((uint16_t)0x0050)
#define TIM_TS_CC1FP1                         ((uint16_t)0x0060)
#define TIM_TS_EXTRG                          ((uint16_t)0x0070)
#define TIM_TS_T2FF                           ((uint16_t)0x0000)
#define IS_TIM_TRIGGER_SELECTION(SELECTION) (((SELECTION) == TIM_TS_CC0F_RF) || \
                                             ((SELECTION) == TIM_TS_CC0FP0) || \
                                             ((SELECTION) == TIM_TS_CC1FP1) || \
                                             ((SELECTION) == TIM_TS_EXTRG) || \
                                             ((SELECTION) == TIM_TS_T2FF))

/** @defgroup TIM_Output_Compare_Preload_State 
  * @{
  */
#define TIM_OCPreload_Enable               ((uint16_t)0x0001)
#define TIM_OCPreload_Disable              ((uint16_t)0x0000)
#define IS_TIM_OCPRELOAD_STATE(STATE) (((STATE) == TIM_OCPreload_Enable) || \
                                       ((STATE) == TIM_OCPreload_Disable))

/** @defgroup TIM_Update_Source 
  * @{
  */
#define TIM_UpdateSource_Global            ((uint16_t)0x0000) /*!< Source of update is the counter overflow/underflow
                                                                   or the setting of UG bit, or an update generation
                                                                   through the slave mode controller. */
#define TIM_UpdateSource_Regular           ((uint16_t)0x0001) /*!< Source of update is counter overflow/underflow. */
#define IS_TIM_UPDATE_SOURCE(SOURCE) (((SOURCE) == TIM_UpdateSource_Global) || \
                                      ((SOURCE) == TIM_UpdateSource_Regular))

/** @defgroup TIM_Flags 
  * @{
  */
#define TIM_CC3_EDGE_FLAG                     ((uint32_t)0x80000)
#define TIM_CC2_EDGE_FLAG                     ((uint32_t)0x40000)
#define TIM_CC1_EDGE_FLAG                     ((uint32_t)0x20000)
#define TIM_CC0_EDGE_FLAG                     ((uint32_t)0x10000)
#define IS_TIM_GET_FLAG(FLAG) (((FLAG) == TIM_CC3_EDGE_FLAG) || \
                               ((FLAG) == TIM_CC2_EDGE_FLAG) || \
                               ((FLAG) == TIM_CC1_EDGE_FLAG) || \
                               ((FLAG) == TIM_CC0_EDGE_FLAG))

/** @defgroup TIM_External_Trigger_Polarity 
  * @{
  */ 
#define TIM_ExtTRGPolarity_Inverted        ((uint16_t)0x8000)
#define TIM_ExtTRGPolarity_NonInverted     ((uint16_t)0x0000)
#define IS_TIM_EXT_POLARITY(POLARITY) (((POLARITY) == TIM_ExtTRGPolarity_Inverted) || \
                                       ((POLARITY) == TIM_ExtTRGPolarity_NonInverted))

/** @defgroup TIM_External_Trigger_Filter 
  * @{
  */
#define IS_TIM_EXT_FILTER(EXTFILTER) ((EXTFILTER) <= 0xF)

/** @defgroup TIM_External_Trigger_Prescaler 
  * @{
  */
#define TIM_ExtTRGPSC_DIV1                 ((uint16_t)0x0000)
#define TIM_ExtTRGPSC_DIV2                 ((uint16_t)0x1000)
#define TIM_ExtTRGPSC_DIV4                 ((uint16_t)0x2000)
#define TIM_ExtTRGPSC_DIV8                 ((uint16_t)0x3000)
#define IS_TIM_EXT_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ExtTRGPSC_DIV1) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV2) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV4) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV8))

/* ---------------------- TIM registers bit mask ------------------------ */
#define SMCR_ETR_Mask               ((uint16_t)0x00FF) 


/*******************  Bit definition for TIM_CR1 register  ********************/
#define  TIM_CR1_URS                         ((uint16_t)0x0020)            /*!< Update request source */
#define  TIM_CR1_UDIS                        ((uint16_t)0x1000)            /*!< Update disable */
#define  TIM_CR1_OPM                         ((uint16_t)0x4000)            /*!< One pulse mode */
#define  TIM_CR1_DIR                         ((uint16_t)0x0010)         
/*******************  Bit definition for TIM_CR2 register  ********************/
#define  TIM_CR2_CCDS                        ((uint16_t)0x0008)            /*!< Capture/Compare DMA Selection */

#define  TIM_CR2_TRGOEN                       ((uint16_t)0xF000)           /*!< [15:12] bits (CCx_TRGOEN) */
#define  TIM_CR2_TRGO0EN                      ((uint16_t)0x1000) 
#define  TIM_CR2_TRGO1EN                      ((uint16_t)0x2000)
#define  TIM_CR2_TRGO2EN                      ((uint16_t)0x4000)
#define  TIM_CR2_TRGO3EN                      ((uint16_t)0x8000)

/*******************  Bit definition for TIM_EGR register  ********************/
#define  TIM_TG_EVENT                         ((uint16_t)0x0400) 
#define  TIM_BG_EVENT                         ((uint16_t)0x0200) 
#define  TIM_UG_EVENT                         ((uint16_t)0x0100) 
#define  TIM_CMP3_EVENT                       ((uint16_t)0x0080) 
#define  TIM_CMP2_EVENT                       ((uint16_t)0x0040)  
#define  TIM_CMP1_EVENT                       ((uint16_t)0x0020)  
#define  TIM_CMP0_EVENT                       ((uint16_t)0x0010) 
#define  TIM_CAP3_EVENT                       ((uint16_t)0x0008) 
#define  TIM_CAP2_EVENT                       ((uint16_t)0x0004)  
#define  TIM_CAP1_EVENT                       ((uint16_t)0x0002)  
#define  TIM_CAP0_EVENT                       ((uint16_t)0x0001) 

/******************  Bit definition for TIM_CCCR register  *******************/

#define  TIM_CCCR_OC3PE                     ((uint32_t)0x800000)            /*!< Output Compare 3 Preload enable */
#define  TIM_CCCR_OC2PE                     ((uint32_t)0x400000)            /*!< Output Compare 3 Preload enable */
#define  TIM_CCCR_OC1PE                     ((uint32_t)0x200000)            /*!< Output Compare 3 Preload enable */
#define  TIM_CCCR_OC0PE                     ((uint32_t)0x100000)            /*!< Output Compare 3 Preload enable */


/*******************  Bit definition for TIM_SMCR register  *******************/
#define  TIM_SMCR_SMS                        ((uint16_t)0x0007)            /*!< SMS[2:0] bits (Slave mode selection) */
#define  TIM_SMCR_SMS_0                      ((uint16_t)0x0001)            /*!< Bit 0 */
#define  TIM_SMCR_SMS_1                      ((uint16_t)0x0002)            /*!< Bit 1 */
#define  TIM_SMCR_SMS_2                      ((uint16_t)0x0004)            /*!< Bit 2 */

#define  TIM_SMCR_TS                         ((uint16_t)0x0070)            /*!< TS[2:0] bits (Trigger selection) */
#define  TIM_SMCR_TS_0                       ((uint16_t)0x0010)            /*!< Bit 0 */
#define  TIM_SMCR_TS_1                       ((uint16_t)0x0020)            /*!< Bit 1 */
#define  TIM_SMCR_TS_2                       ((uint16_t)0x0040)            /*!< Bit 2 */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define  TIM_BDTR_OSSI                       ((uint16_t)0x0400)            /*!< Off-State Selection for Idle mode */
#define  TIM_BDTR_OSSR                       ((uint16_t)0x0800)            /*!< Off-State Selection for Run mode */
#define  TIM_BDTR_BKE                        ((uint16_t)0x1000)            /*!< Break enable */
#define  TIM_BDTR_BKP                        ((uint16_t)0x2000)            /*!< Break Polarity */
#define  TIM_BDTR_AOE                        ((uint16_t)0x4000)            /*!< Automatic Output enable */
#define  TIM_BDTR_MOE                        ((uint16_t)0x8000)            /*!< Main Output enable */

/*******************************************************************************/
/*比较模式1输出状态配置*/
void TIM_OC0_IDConfig(TIMER_Type* TIMx, uint16_t TIM_OCxID);
void TIM_OC1_IDConfig(TIMER_Type* TIMx, uint16_t TIM_OCxID);
void TIM_OC2_IDConfig(TIMER_Type* TIMx, uint16_t TIM_OCxID);
void TIM_OC3_IDConfig(TIMER_Type* TIMx, uint16_t TIM_OCxID);
/*捕获输入配置*/
static void TI0_Config(TIMER_Type* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,uint16_t TIM_ICFilter);
static void TI1_Config(TIMER_Type* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,uint16_t TIM_ICFilter);
static void TI2_Config(TIMER_Type* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,uint16_t TIM_ICFilter);
static void TI3_Config(TIMER_Type* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,uint16_t TIM_ICFilter);
                                                                                                             
void TIM_ICInit(TIMER_Type* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);                                    //芯片初始化
void TIM_BDTRConfig(TIMER_Type* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);                            //刹车控制初始化

void TIM_ClearBreakFlag(TIMER_Type* TIMx);                                                                 //清除刹车标记
void TIM_ClearITPendingBit(TIMER_Type* TIMx, uint32_t TIM_IT);                                             //清除中断标记
void TIM_Cmd(TIMER_Type* TIMx, FunctionalState NewState);                                                  //计数使能控制
void TIM_CounterModeConfig(TIMER_Type* TIMx, uint16_t TIM_CounterMode);                                    //配置计数模式
void TIM_CtrlPWMOutputs(TIMER_Type* TIMx, FunctionalState NewState);                                       //配置主输出使能控制
void TIM_DMACmd(TIMER_Type* TIMx, uint32_t TIM_DMASource, FunctionalState NewState);                       //DMA请求使能
void TIM_ETRClockMode1Config(TIMER_Type* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,uint16_t ExtTRGFilter);    //外部时钟1下的触发器模式                                                       //外部时钟1下的触发器模式
void TIM_ETRClockMode2Config(TIMER_Type* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);   //外部时钟2下的触发器模式
void TIM_ETRConfig(TIMER_Type* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,uint16_t ExtTRGFilter);                                                                  // 配置TIMx外部触发器(ETR)

/*获取捕获值*/
uint16_t TIM_GetCapture0(TIMER_Type* TIMx);
uint16_t TIM_GetCapture1(TIMER_Type* TIMx);
uint16_t TIM_GetCapture2(TIMER_Type* TIMx);
uint16_t TIM_GetCapture3(TIMER_Type* TIMx);

uint16_t TIM_GetCounter(TIMER_Type* TIMx); //获取计数
FlagStatus TIM_GetFlagStatus(TIMER_Type* TIMx, uint32_t TIM_FLAG);//获取输入信号状态标志
ITStatus TIM_GetITStatus(TIMER_Type* TIMx, uint32_t TIM_IT);//获取中断标志
uint16_t TIM_GetPrescaler(TIMER_Type* TIMx);//获取PSC的值
void TIM_ITConfig(TIMER_Type* TIMx, uint32_t TIM_IT, FunctionalState NewState);//中断使能配置

/*通道初始化*/
void TIM_OC0Init(TIMER_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC1Init(TIMER_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIMER_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIMER_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
/*设置捕获极性选择*/
void TIM_OC0PolarityConfig(TIMER_Type* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC1PolarityConfig(TIMER_Type* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC2PolarityConfig(TIMER_Type* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC3PolarityConfig(TIMER_Type* TIMx, uint16_t TIM_OCPolarity);

/*设置预分频使能*/
void TIM_OC0PreloadConfig(TIMER_Type* TIMx, uint16_t TIM_OCPreload);
void TIM_OC1PreloadConfig(TIMER_Type* TIMx, uint16_t TIM_OCPreload);
void TIM_OC2PreloadConfig(TIMER_Type* TIMx, uint16_t TIM_OCPreload);
void TIM_OC3PreloadConfig(TIMER_Type* TIMx, uint16_t TIM_OCPreload);

void TIM_EGRConfig(TIMER_Type* TIMx, uint16_t TIM_ET);                                //设置TIMx事件产生
void TIM_SelectCCDMA(TIMER_Type* TIMx, FunctionalState NewState);//选择TIMx外设捕获比较DMA源
void TIM_SelectInputTrigger(TIMER_Type* TIMx, uint16_t TIM_InputTriggerSource);//选择输入触发器源
void TIM_SelectOnePulseMode(TIMER_Type* TIMx, uint16_t TIM_OPMode);//选择TIMx的单脉冲模式
void TIM_SelectOutputTrigger(TIMER_Type* TIMx, uint16_t TIM_TRGOSource);//选择TIMx触发输出启用
void TIM_SelectSlaveMode(TIMER_Type* TIMx, uint16_t TIM_SlaveMode);//选择TIMx从模式
void TIM_SetCounter(TIMER_Type* TIMx, uint16_t Counter);//设置TIMx计数器寄存器值
void TIM_SetAutoreload(TIMER_Type* TIMx, uint16_t Autoreload);//设置TIMx自动加载寄存器值
/*设置比较值*/
void TIM_SetCompare0(TIMER_Type* TIMx, uint16_t Compare0);
void TIM_SetCompare1(TIMER_Type* TIMx, uint16_t Compare1);
void TIM_SetCompare2(TIMER_Type* TIMx, uint16_t Compare2);
void TIM_SetCompare3(TIMER_Type* TIMx, uint16_t Compare3);

void TIM_TimeBaseInit(TIMER_Type* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);//初始化TIMx时间基准单元外设
void TIM_UpdateDisableConfig(TIMER_Type* TIMx, FunctionalState NewState);//启用或禁用TIMx Update事件
void TIM_UpdateRequestConfig(TIMER_Type* TIMx, uint16_t TIM_UpdateSource);//配置TIMx更新请求中断源
#endif

