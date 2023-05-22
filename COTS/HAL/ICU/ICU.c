
#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "TIM1.h"
#include "TIM1_Prv.h"
#include "ICU.h"

static void(*ISR)(void) = NULL;
#define ISR_IMP(ISR_No) void __vector_##ISR_No (void) __attribute__((signal));\
						void __vector_##ISR_No (void)

u32 Glob_u32OVF = 0;

void ICU_vidInit(void) {

    /* enable overflow interrupt */

    TIMSK |= (1 << TOIE1);
    /* clear input capture Flag */
    TIFR |= (1 << ICF1);
    /* clear overflow Flag */

    TIFR |= (1 << TOV1);
    /* clear TCCR1A & TCNT1 Registers */
    TCCR1A = 0;
    TCNT1 = 0;
    TCCR1B &= ICU_PREClrMask;
    TCCR1B |= (ICU_PrescalerSelection << CS10);

    TCCR1B &= ~(1 << ICES1);
    TCCR1B |= (ICU_EdgSelection << ICES1);


}

ICU_enuErrorStatus_t ICU_enuEdgeSelect(u8 Cpy_u8Edge) {
    TCCR1B &= ~(1 << ICES1);
    TCCR1B |= (Cpy_u8Edge << ICES1);
}

ICU_enuErrorStatus_t ICU_enuMesureSignal(u8* Add_u8Freq, u8* Add_u8Duty) {
    u16 Loc_u16temp1 = 0, Loc_u16temp2 = 0, Loc_u16temp3 = 0;


    while ((TIFR & (1 << ICF1)) == 0);
    Loc_u16temp1 = ICR1;
    /* clear input capture Flag */
    TIFR |= (1 << ICF1);

    ICU_enuEdgeSelect(ICU_Falling);

    Loc_u16temp2 = ICR1;
    /* clear input capture Flag */
    TIFR |= (1 << ICF1);
    ICU_enuEdgeSelect(ICU_Rising);

    Loc_u16temp3 = ICR1;
    /* clear input capture Flag */
    TIFR |= (1 << ICF1);
    /* stop timer */
    TCCR1B &= ICU_StopTIM;
    /*setup freq */
    if ((Loc_u16temp1 < Loc_u16temp2) && (Loc_u16temp2 < Loc_u16temp3)) {
        *Add_u8Duty = ((Loc_u16temp2 - Loc_u16temp1)*100) / (Loc_u16temp3 - Loc_u16temp1);
        *Add_u8Freq = CpuFreq1 / (Loc_u16temp3 - Loc_u16temp1);

    }
}

ICU_enuErrorStatus_t ICU_enuGetCount(u32* Add_pu32Count) {


    TCNT1 = 0;
    Glob_u32OVF = 0;
    ICU_enuEdgeSelect(ICU_Rising);
    /* clear input capture Flag */
    TIFR |= (1 << ICF1);
    /* clear overflow Flag */

    TIFR |= (1 << TOV1);
    while (!(TIFR & (1 << ICF1)));
    TCNT1 = 0;
    ICU_enuEdgeSelect(ICU_Falling);
    /* clear input capture Flag */
    TIFR |= (1 << ICF1);
    /* clear overflow Flag */
    TIFR |= (1 << TOV1);
    Glob_u32OVF = 0;

    while (!(TIFR & (1 << ICF1)));
    *Add_pu32Count = ICR1 + (65535 * Glob_u32OVF);

}

ISR_IMP(9) {
    Glob_u32OVF++;
}