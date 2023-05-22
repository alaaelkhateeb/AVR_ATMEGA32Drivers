/* 
 * File:   Led.h
 * Author: alaa
 *
 * Created on 17 ?????, 2023, 10:21 ?
 */

#ifndef LED_H
#define	LED_H


#include "Led_Cfg.h"

typedef enum {
    LED_enuOk = 0,
    LED_enuNotOk
}LED_tenuErrorStatus;



LED_tenuErrorStatus LED_enuLedON(LED_tenuLEDNumber Cpy_u8LED_Num);

LED_tenuErrorStatus LED_enuLedOFF(LED_tenuLEDNumber Cpy_u8LED_Num);
LED_tenuErrorStatus LED_enuLedToggle(LED_tenuLEDNumber Cpy_u8LED_Num) ;
#endif	/* LED_H */

