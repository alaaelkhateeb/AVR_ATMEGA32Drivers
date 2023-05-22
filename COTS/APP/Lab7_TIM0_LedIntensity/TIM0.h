/* 
 * File:   TIM0.h
 * Author: alaa
 *
 * Created on March 2, 2023, 1:52 PM
 */

#ifndef TIM0_H
#define	TIM0_H


#define TIM0_Mode_Selection             TIM_ModeFastPWM


#define TIM_ModeNormal                  0b00000000
#define TIM_ModePWMPhase                0b01000000
#define TIM_ModeCTC                     0b00001000
#define TIM_ModeFastPWM                 0b01001000



#define TIM_CLK_PRESCALER_Selection     TIM_ClkDiv8
#define TIM0_OC0PinNonPWM_Selection         TIM0_ToggleOC0
#define TIM0_OC0PinFastPWM_Selection         TIM0_ClearOC0_OnCompSetTop
#define TIM0_OC0PinPhaseCorrectPWM_Selection         TIM0_ClearOC0_OnCompUpCount

#define TIM0_ModeClrMask 0b10110111
#define TIM0_PREClrMask  0b11111000
#define TIM0_OC0ClrMask  0b11001111

typedef enum {
    TIM0_enuOk = 0,
    TIM0_enuNotOk,
    TIM0_enuNullPtr,
    TIM0_enuWrongValue
} TIM0_enuErrorStatus;

typedef enum {
    TIM_NoClkSrc = 0,
    TIM_Clk,
    TIM_ClkDiv8,
    TIM_ClkDiv64,
    TIM_ClkDiv256,
    TIM_ClkDiv1024,
    TIM_EXTPinFalling,
    TIM_EXTPinrising
} TIM_enuClkSelect;

/*
 typedef enum {
    TIM_ModeNormal = 0,
    TIM_ModePWMPhase,
    TIM_ModeCTC,
    TIM_ModeFastPWM
} TIM_enuModeSelect;
 
 
 */
typedef enum {
    TIM0_NormalPortOp = 0,
    TIM0_ToggleOC0,
    TIM0_ClearOC0,
    TIM0_SetOC0

} TIM0_enuOC0_NonPWM;
typedef enum {
    TIM0_NormalPortOp0 = 0,
    TIM0_Reserved,
    TIM0_ClearOC0_OnCompSetTop,
    TIM0_SetOC0_OnCompClrTop

} TIM0_enuOC0_FastPWM;
typedef enum {
    TIM0_NormalPortOp1 = 0,
    TIM0_Reserved1,
    TIM0_ClearOC0_OnCompUpCount,
    TIM0_SetOC0_OnCompUpCount

} TIM0_enuOC0_PhaseCorrectPWM;
void TIM0_vidInit(void);

TIM0_enuErrorStatus TIM0_enuSetTickTimeMS(u16 Copy_u16TickTime, u32 Copy_u32Clock);
TIM0_enuErrorStatus TIM0_enuStart(void);
TIM0_enuErrorStatus TIM0_enuStop(void);
TIM0_enuErrorStatus TIM0_enuRegisterCallback(void (*TIM0cbf_t)(void));
TIM0_enuErrorStatus TIM0_enuSetOCRValue(u8 cpy_u8Value);
TIM0_enuErrorStatus TIM0_enuGeneratePWM(u8 Copy_u8DutyCycle );
#endif	/* TIM0_H */

