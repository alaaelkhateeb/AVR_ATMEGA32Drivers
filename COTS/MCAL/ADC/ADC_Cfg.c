#include "DIO.h"
#include "ADC_Cfg.h"


 const ADC_Str_cfg_t ADC_Config[ADC_ChannelsNum]={
    /*config pinnumber portnumber  Mode*/
    {DIO_enuPin0, DIO_PORTA},
    {DIO_enuPin1, DIO_PORTA},
};