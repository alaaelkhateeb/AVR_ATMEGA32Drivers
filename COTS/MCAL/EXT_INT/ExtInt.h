/* 
 * File:   ExtInt.h
 * Author: alaa
 *
 * Created on January 27, 2023, 10:17 AM
 */

#ifndef EXTINT_H
#define	EXTINT_H

typedef enum {
     ExtInt_INT2=5,
    ExtInt_INT0 = 6,
    ExtInt_INT1
   
 } ExtInt_tenuNumSelection;

typedef enum {
    ExtInt_enuOk = 0,
    ExtInt_enuNotOk
} ExtInt_tenuErrorStatus;

typedef enum {
    ExtInt_enuLowLevel = 0,
    ExtInt_enuAnyLogic,
    ExtInt_enuFalling,
    ExtInt_enuRising
} ExtInt_tenuINTControl;

typedef enum {
    ExtInt_enuDisable = 0,
    ExtInt_enuEn
} ExtInt_tenuEnDis;

void ExtInt_Init();
void ExtInt_Enable();
void ExtInt_Disable();
#endif	/* EXTINT_H */

