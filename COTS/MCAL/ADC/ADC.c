
#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "ADC.h"
#include "ADC_Cfg.h"
#include "ADC_Prv.h"

ADC_tenuErrorStatus ADC_enuInit(void) {
    u8 Loc_u8Status = ADC_enuOk;
    /*CLEAR REG*/
    ADMUX &= ADC_ADMUX_CLR_Mask;
    /*Select Voltage Reference*/
    ADMUX |= (ADC_RefSourceSelection << REFS0);


    #if ADC_AdjustSelection == ADC_RightAdjust
        ADMUX |= (1 << ADLAR);

    #elif   ADC_AdjustSelection ==  ADC_LeftAdjust
        ADMUX &= ~(1 << ADLAR);
    #endif 
    #if ADC_INT_ENABLE
        ADCSRA |= (1 << ADIE);
    #else
        ADCSRA &= ~(1 << ADIE);
    #endif
        ADCSRA |= (ADC_PRESCLAR_SELECTION << ADPS0);
        /*enabling reg*/
    #if ADC_Enable == ADC_ON
        ADCSRA |= (1 << ADEN);

    #elif   ADC_Enable ==  ADC_OFF
        ADCSRA &= ~(1 << ADEN);
    #endif 
    return Loc_u8Status;

}

ADC_tenuErrorStatus ADC_enuGetADCValue(ADC_tenuChannels ADC_EnuChSelect, u16* Add_pu16Data) {
    u8 Loc_u8Counter = 0xFF;
    u8 Loc_u8Status = ADC_enuOk;
    if ((ADC_EnuChSelect >= ADC_enuChannel0)&&(ADC_EnuChSelect <= ADC_enuChannel7)) {
        if (Add_pu16Data != NULL) {
            ADMUX &= 0xE0;
            /*channelSelection**/
            ADMUX |= (ADC_EnuChSelect);
            /* startConversion */
            ADCSRA |= (1 << ADSC);
#if (!ADC_INT_ENABLE)
            while (!(ADCSRA & (1 << ADIF)) && (Loc_u8Counter)) {
                Loc_u8Counter--;
            }
#endif
            if (Loc_u8Counter < 0) {
                Loc_u8Status = ADC_enuTimeOut;
            }
#if (ADC_AdjustSelection == ADC_RightAdjust)
            *Add_pu16Data = ADCL;
            *Add_pu16Data |= (ADCH << 8);
#elif   (ADC_AdjustSelection ==  ADC_LeftAdjust)
            *Add_pu16Data = (ADCL >> 6);
            *Add_pu16Data |= (ADCH << 2);
#endif 

        } else {
            Loc_u8Status = ADC_enuNullPtr;
        }

    }
    return Loc_u8Status;

}

ADC_tenuErrorStatus ADC_enuStartAutoTrigger(ADC_tenuAutoTriggerSource cpySource) {
    u8 Loc_u8Status = ADC_enuOk;
#if ADC_AUTO_TRIGER_ENABLE
    /*clearbits 5->7*/
    SFIOR &= 0x1F;
    SFIOR |= (cpySource << 5);
#endif
    return Loc_u8Status;

}
