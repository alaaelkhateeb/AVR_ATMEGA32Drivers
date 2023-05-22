#include "DIO.h"
#include "Led_Cfg.h"




const LED_strCfg_t LED_Confg[LEDs_Numbers] = {
    
     /*config pinnumber portnumber  Mode*/
    { DIO_enuPin0, DIO_PORTA, Active_High},
    { DIO_enuPin1, DIO_PORTA, Active_High},
    { DIO_enuPin2, DIO_PORTA, Active_High},
    { DIO_enuPin3, DIO_PORTA, Active_High},
    { DIO_enuPin4, DIO_PORTA, Active_High},
    { DIO_enuPin5, DIO_PORTA, Active_High},
    { DIO_enuPin6, DIO_PORTA, Active_High},
    { DIO_enuPin7, DIO_PORTA, Active_High},
};
