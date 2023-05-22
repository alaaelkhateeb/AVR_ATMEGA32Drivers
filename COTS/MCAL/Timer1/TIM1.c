#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "TIM1.h"
#include "TIM1_Prv.h"

void TIM1_vidInit(void) {
    /*mode selection*/
    TCCR1A &= TIM1_ModeClrMask;
    TCCR1A |= TIM1_Mode_Selection;
#if TIM1_Mode_Selection ==TIM1_ModeNormal 

    TCCR1B |= (0 << WGM12);
#elif  TIM1_Mode_Selection ==TIM1_ModePWMPhase
    TCCR1B |= (2 << WGM12);
#elif  TIM1_Mode_Selection ==TIM1_ModeFastPWM
    TCCR1B |= (3 << WGM12);
#elif TIM1_Mode_Selection ==TIM1_ModeCTC 
    TCCR1B |= (3 << WGM12);

#endif
    TCCR1A &= TIM1_OC1A_BClrMask;
    /*oc0 pin mode*/
#if TIM1_Mode_Selection ==TIM1_ModeNormal 
    TCCR1A |= (TIM1_OC1A_BPinNonPWM_Selection << COM1B0);
    TCCR1A |= (TIM1_OC1A_BPinNonPWM_Selection << COM1A0);
#elif  TIM1_Mode_Selection ==TIM1_ModePWMPhase

    TCCR1A |= (TIM0_OC0PinPhaseCorrectPWM_Selection << COM1B0);
    TCCR1A |= (TIM0_OC0PinPhaseCorrectPWM_Selection << COM1A0);
#elif  TIM1_Mode_Selection ==TIM1_ModeFastPWM
    TCCR1A |= (TIM1_OC1A_BPinFastPWM_Selection << COM1B0);
    TCCR1A |= (TIM1_OC1A_BPinFastPWM_Selection << COM1A0);
#elif TIM1_Mode_Selection ==TIM1_ModeCTC 
    TCCR1A |= (TIM1_OC1A_BPinNonPWM_Selection << COM1B0);
    TCCR1A |= (TIM1_OC1A_BPinNonPWM_Selection << COM1A0);

#endif

ICR1 = (CpuFreq/((u32)TIM1_Prescaler))-1;

}

TIM1_enuErrorStatus TIM1_enuStart(void) {
    TCCR1B &= TIM1_PREClrMask;
    TCCR1B |= (TIM1_CLK_PRESCALER_Selection << CS10);
}

TIM1_enuErrorStatus TIM1_enuSetCompareAvalue(u16 Cpy_u16data) {
    OCR1A = Cpy_u16data;
}

TIM1_enuErrorStatus TIM1_enuSetCompareBvalue(u16 Cpy_u16data) {
    OCR1B = Cpy_u16data;
}
