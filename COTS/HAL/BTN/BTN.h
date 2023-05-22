/* 
 * File:   BTN.h
 * Author: alaa
 *
 * Created on January 18, 2023, 12:29 PM
 */

#ifndef BTN_H
#define	BTN_H

#include "BTN_Cfg.h"

#define NumberOfBTNs 2

typedef enum {
   BTN_enuOk = 0,
   BTN_enuNotOk
} BTN_tenuErrorStatus;

BTN_tenuErrorStatus BTN_enuIsPressed(BTN_tenuBTNNumber Cpy_u8DIO_Pinnum, u8* Add_u8PinValue);


#endif	/* BTN_H */

