#include "DIO.h"
#include "BTN_Cfg.h"



const BTNStr_cfg_t BTN_Config[BTNs_Numbers]={
    /*config pinnumber portnumber  Mode*/
    {DIO_enuPin26, DIO_PORTD, BTN_Active_High},
    {DIO_enuPin27, DIO_PORTD, BTN_Active_High},
};