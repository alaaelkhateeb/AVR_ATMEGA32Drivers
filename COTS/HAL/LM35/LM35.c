#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "ADC.h"
#include "LM35.h"
#include "LM35_Cfg.h"

void LM35_vidInit(void){
    ADC_enuInit();
}

void LM35_vidGetReading(ADC_tenuChannels ADC_ChSelect,u16* Add_Pu16Value){
    ADC_enuGetADCValue(ADC_ChSelect,Add_Pu16Value);
    *Add_Pu16Value =(u16)(((u32)*Add_Pu16Value*5000UL)/1023UL)/10;
}