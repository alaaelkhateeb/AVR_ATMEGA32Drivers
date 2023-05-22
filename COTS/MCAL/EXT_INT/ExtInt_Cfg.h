/* 
 * File:   ExtInt_Cfg.h
 * Author: alaa
 *
 * Created on January 27, 2023, 10:17 AM
 */

#ifndef EXTINT_CFG_H
#define	EXTINT_CFG_H
#include "ExtInt.h"

#define ExtInt_Number 2


typedef struct{
    ExtInt_tenuINTControl ExtInt_enuMode;
    ExtInt_tenuEnDis    ExtInt_enuOnOff;
            
}ExtIntStr_cfg_t;

  /* ExtInt_enuDisable ExtInt_enuEn*/
/** ExtInt_enuLowLevel  ExtInt_enuAnyLogic   ExtInt_enuFalling
                                ExtInt_enuRising*/
#define ExtInt0_Mode     ExtInt_enuRising
#define ExtInt0_OnOff    ExtInt_enuEn

#define ExtInt1_Mode     ExtInt_enuRising
#define ExtInt1_OnOff    ExtInt_enuEn


 /*ExtInt_enuFalling     ExtInt_enuRising*/
#define ExtInt2_Mode     ExtInt_enuLowLevel
#define ExtInt2_OnOff    ExtInt_enuDisable


//extern const ExtIntStr_cfg_t ExtInt_cfg[ExtInt_Number];


#endif	/* EXTINT_CFG_H */

