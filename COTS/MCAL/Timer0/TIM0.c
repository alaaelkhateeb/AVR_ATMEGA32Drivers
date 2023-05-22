
#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "ADC.h"
#include "TIM0.h"
#include "TIM0_Prv.h"

#define CPUFreq     8000000UL
static void(*ISR)(void) = NULL;
#define ISR_IMP(ISR_No) void __vector_##ISR_No (void) __attribute__((signal));\
						void __vector_##ISR_No (void)
u8 Glob_u8Preload = 0, Glob_u8OVCounter = 0;
f32 Glob_f32OVFCount = 0;

void TIM0_vidInit(void) {

    /*mode selection*/
    TCCR0 &= TIM0_ModeClrMask;
    TCCR0 |= TIM0_Mode_Selection;
    /*oc0 pin mode*/
#if TIM0_Mode_Selection ==TIM_ModeNormal 
    TCCR0 &= TIM0_OC0ClrMask;
    TCCR0 |= (TIM0_OC0PinNonPWM_Selection << 4);
#elif  TIM0_Mode_Selection ==TIM_ModePWMPhase
    TCCR0 &= TIM0_OC0ClrMask;
    TCCR0 |= (TIM0_OC0PinPhaseCorrectPWM_Selection << 4);
#elif  TIM0_Mode_Selection ==TIM_ModeFastPWM
    TCCR0 &= TIM0_OC0ClrMask;
    TCCR0 |= (TIM0_OC0PinFastPWM_Selection << 4);
#elif TIM0_Mode_Selection ==TIM_ModeCTC 
    TCCR0 &= TIM0_OC0ClrMask;
    TCCR0 |= (TIM0_OC0PinNonPWM_Selection << 4);

#endif


    /*int enable*/
#if TIM0_Mode_Selection==TIM_ModeCTC
    TIMSK |= (1 << OCIE0);
#else 
    TIMSK |= (1 << TOIE0);
#endif
}

TIM0_enuErrorStatus TIM0_enuSetTickTimeMS(u16 Copy_u16TickTime, u32 Copy_u32ClkPre) {
    TIM0_enuErrorStatus Loc_enuStatus = TIM0_enuOk;
    f32 Loc_f32OVFTime = 0;
    f32 Loc_f32FloatPart = 0;
    u8 Glob_u8Preload = 0, Glob_u8OVCounter = 0;
    f32 Glob_f32OVFCount = 0;

    Loc_f32OVFTime = (f32) (256 * (Copy_u32ClkPre / CPUFreq));
    if (TIM0_Mode_Selection == TIM_ModeCTC) {

    } else {
        if (Copy_u16TickTime > Loc_f32OVFTime) {
                Glob_f32OVFCount = (f32) (Copy_u16TickTime / (Loc_f32OVFTime * 1000));
                Loc_f32FloatPart=Glob_f32OVFCount-(u32)Glob_f32OVFCount;
            if (Loc_f32FloatPart == 0) {
                Glob_u8Preload = 0;
            } else {
                Glob_u8Preload=256-(256*Loc_f32FloatPart);
            }
        } else if (Copy_u16TickTime < Loc_f32OVFTime) {
            Glob_f32OVFCount = (Copy_u16TickTime * 256) / (Loc_f32OVFTime * 1000);
            Glob_u8Preload = 256 - Glob_f32OVFCount;
        }
        TCNT0 = Glob_u8Preload;
    }


    return Loc_enuStatus;




}

TIM0_enuErrorStatus TIM0_enuStart(void) {
    TCCR0 &= TIM0_PREClrMask;
    TCCR0 |= TIM_CLK_PRESCALER_Selection;
}

TIM0_enuErrorStatus TIM0_enuStop(void) {
    TCCR0 &= TIM0_PREClrMask;
    TCCR0 |= TIM_NoClkSrc;
}

TIM0_enuErrorStatus TIM0_enuRegisterCallback(void (*TIM0cbf_t)(void)) {
    TIM0_enuErrorStatus Loc_enuStatus = TIM0_enuOk;

    if (TIM0cbf_t == NULL) {
        Loc_enuStatus = TIM0_enuNullPtr;
    } else {
        ISR = TIM0cbf_t;
    }

    return Loc_enuStatus;
}

TIM0_enuErrorStatus TIM0_enuSetOCRValue(u8 cpy_u8Value) {
    OCR0 = cpy_u8Value;
}

TIM0_enuErrorStatus TIM0_enuGeneratePWM(u8 Copy_u8DutyCycle) {
    TIM0_enuErrorStatus Loc_enuStatus = TIM0_enuOk;
    u8 Loc_u8TempValue = 0;
    if (TIM0_Mode_Selection == TIM_ModeFastPWM) {
        if (TIM0_OC0PinFastPWM_Selection == TIM0_SetOC0_OnCompClrTop) {
            Loc_u8TempValue = 255 - (255 * Copy_u8DutyCycle) / 100;
            TIM0_enuSetOCRValue(Loc_u8TempValue);
        } else if (TIM0_OC0PinFastPWM_Selection == TIM0_ClearOC0_OnCompSetTop) {
            Loc_u8TempValue = (255 * Copy_u8DutyCycle) / 100;
            TIM0_enuSetOCRValue(Loc_u8TempValue);
        } else {
            Loc_enuStatus = TIM0_enuNotOk;
        }
    } else if (TIM0_Mode_Selection == TIM_ModePWMPhase) {
        if (TIM0_OC0PinPhaseCorrectPWM_Selection == TIM0_SetOC0_OnCompUpCount) {
            Loc_u8TempValue = 255 - (255 * Copy_u8DutyCycle) / 100;
            TIM0_enuSetOCRValue(Loc_u8TempValue);
        } else if (TIM0_OC0PinPhaseCorrectPWM_Selection == TIM0_ClearOC0_OnCompUpCount) {
            Loc_u8TempValue = (255 * Copy_u8DutyCycle) / 100;
            TIM0_enuSetOCRValue(Loc_u8TempValue);
        } else {
            Loc_enuStatus = TIM0_enuNotOk;
        }
    } else {
        Loc_enuStatus = TIM0_enuNotOk;
    }
    return Loc_enuStatus;
}

ISR_IMP(11) {
    // TIFR |= (1 << TOV0);
    	Glob_u8OVCounter++;
		
	if(Glob_u8OVCounter == (u32) Glob_f32OVFCount+1){
    ISR();
        Glob_u8OVCounter=0;
        TCNT0=Glob_u8Preload;
}
}


//ISR_IMP(10) {
//    ///compare match
//    // TIFR |= (1 << OCF0);
//    ISR();
//