/* 
 * File:   TIM1.h
 * Author: alaa
 *
 * Created on April 12, 2023, 4:17 PM
 */

#ifndef TIM1_H
#define	TIM1_H


#define  CpuFreq            8000000UL
#define  TIM1_Prescaler             64


#define TIM1_Mode_Selection                              TIM1_ModeNormal 
#define TIM1_CLK_PRESCALER_Selection     	 		     TIM1_ClkDiv64
#define TIM1_OC1A_BPinNonPWM_Selection          		 TIM1_NormalPortOp
#define TIM1_OC1A_BPinFastPWM_Selection         		 TIM1_ClearOC1A_B_OnCompSetBot
#define TIM1_OC1A_BPinPhaseCorrectPWM_Selection          TIM1_ClearOC1A_B_OnCompUpCount


/*nonPWM*/
#define    TIM1_NormalPortOp 0
#define    TIM1_ToggleOC1A_B    1
#define    TIM1_ClearOC1A_B     2
#define    TIM1_SetOC1A_B		 3

/*fast pwm*/ 
#define   TIM1_NormalPortOp0 			    0
#define   TIM1_ToggleOC1A_OnComp15 		1
#define   TIM1_ClearOC1A_B_OnCompSetBot 		2
#define   TIM1_SetOC1A_B_OnCompClrBot			3

/*phase correct pwm*/
#define   TIM1_NormalPortOp1                0
#define   TIM1_ToggleOC1A_OnComp9 		1
#define   TIM1_ClearOC1A_B_OnCompUpCount		2
#define   TIM1_SetOC1A_BOnCompUpCount			3


#define   TIM1_NoClkSrc      	 0
#define   TIM1_Clk				 1
#define   TIM1_ClkDiv8       	 2
#define   TIM1_ClkDiv64      	 3
#define   TIM1_ClkDiv256		     4
#define   TIM1_ClkDiv1024		 5
#define   TIM1_EXTPinFalling      6
#define   TIM1_EXTPinrising       7

#define TIM1_ModeNormal                  0b00000000
#define TIM1_ModePWMPhase                0b00000011
#define TIM1_ModeCTC                     0b00000000
#define TIM1_ModeFastPWM                 0b00000010

#define TIM1_ModeClrMask 0b11111100
#define TIM1_PREClrMask  0b11111000
#define TIM1_OC1A_BClrMask  0b00001111


typedef enum {
    TIM1_enuOk = 0,
    TIM1_enuNotOk,
    TIM1_enuNullPtr,
    TIM1_enuWrongValue
}TIM1_enuErrorStatus;


void TIM1_vidInit(void);
TIM1_enuErrorStatus TIM1_enuStart(void);
TIM1_enuErrorStatus TIM1_enuSetCompareAvalue(u16 Cpy_u16data);
TIM1_enuErrorStatus TIM1_enuSetCompareBvalue(u16 Cpy_u16data);
#endif	/* TIM1_H */

