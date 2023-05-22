/* 
 * File:   ADC.h
 * Author: alaa
 *
 * Created on February 9, 2023, 12:40 AM
 */

#ifndef ADC_H
#define	ADC_H

#define ADC_ADMUX_ClrMask  0xF8        //11111000
typedef enum {
    ADC_enuOk = 0,
    ADC_enuNotOk,
    ADC_enuNullPtr,

    ADC_enuTimeOut
} ADC_tenuErrorStatus;
typedef enum {
    ADC_enuChannel0 = 0b00000,
    ADC_enuChannel1= 0b00001,
    ADC_enuChannel2= 0b00010,
    ADC_enuChannel3= 0b00011,
    ADC_enuChannel4= 0b00100,
    ADC_enuChannel5= 0b00101,
    ADC_enuChannel6= 0b00110,
    ADC_enuChannel7= 0b00111

} ADC_tenuChannels;

typedef enum {
    ADC_enuFreeRunningMode = 0b000,
    ADC_enuAnalogComparator= 0b001,
    ADC_enuExtIntRequest0= 0b010,
    ADC_enuTim_Count0CompareMatch= 0b011,
    ADC_enuTim_Count0Overflow= 0b100,
    ADC_enuTim_Count1CompareMatch= 0b101,
    ADC_enuTim_Count1Overflow= 0b110,
    ADC_enuTim_Count1CaptureEvent= 0b111

} ADC_tenuAutoTriggerSource;
ADC_tenuErrorStatus ADC_enuInit(void);
ADC_tenuErrorStatus ADC_enuGetADCValue(ADC_tenuChannels ADC_EnuChSelect,u16* Add_pu16Data);

ADC_tenuErrorStatus ADC_enuStartAutoTrigger(ADC_tenuAutoTriggerSource   cpySource);


#endif	/* ADC_H */

