#include "DIO.h"
#include "BTN_Cfg.h"



const BTNStr_cfg_t BTN_Config[BTNs_Numbers]={
    {DIO_enuPin24, DIO_PORTD, BTN_Active_High},
    {DIO_enuPin25, DIO_PORTD, BTN_Active_High},
};