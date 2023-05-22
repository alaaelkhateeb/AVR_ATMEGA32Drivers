/* 
 * File:   SevenSegment.h
 * Author: alaa
 *
 * Created on January 20, 2023, 3:03 PM
 */

#ifndef SEVENSEGMENT_H
#define	SEVENSEGMENT_H
#include "Std_types.h"
#include "SevenSegment_Cfg.h"
                             //dot gfedcba
#define		    SSegNumber0     0b00111111
#define		    SSegNumber1     0b00000110
#define		    SSegNumber2     0b01011011
#define		    SSegNumber3     0b01001111
#define		    SSegNumber4     0b01100110
#define		    SSegNumber5     0b01101101
#define		    SSegNumber6     0b01111101
#define		    SSegNumber7     0b00000111
#define		    SSegNumber8     0b01111111
#define		    SSegNumber9     0b01101111
#define         SSegDot         0b10000000    

typedef enum {
    SevenSeg_enuOk = 0,
    SevenSeg_enuNotOk
} SevenSeg_tenuErrorStatus;

SevenSeg_tenuErrorStatus SevenSeg_enuDisplay(SevenSeg_tenuNumber SSeg_number,u8 Cpy_u8Data);
extern  const u8 SevenSeg_arrNumbers[10];
#endif	/* SEVENSEGMENT_H */

