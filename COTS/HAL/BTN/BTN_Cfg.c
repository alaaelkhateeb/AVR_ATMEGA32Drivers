#include "DIO.h"
#include "BTN_Cfg.h"



const BTNStr_cfg_t BTN_Config[BTNs_Numbers]={
    /*config pinnumber portnumber  Mode*/
    {DIO_enuPin8, DIO_PORTB, BTN_Active_High},
    {DIO_enuPin9, DIO_PORTB, BTN_Active_High},
};