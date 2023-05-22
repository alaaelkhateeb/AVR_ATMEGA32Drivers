/* 
 * File:   LCD_Cfg.h
 * Author: alaa
 *
 * Created on February 10, 2023, 2:04 PM
 */

#ifndef LCD_CFG_H
#define	LCD_CFG_H

#include "DIO.h"

 #define LCD_HalfDataPort_Selection  DIO_PORTA
#define LCD_DataPort_Selection  DIO_PORTD
#define LCD_CtrlPort_Selection  DIO_PORTB

#define LCD_RS                  DIO_enuPin1
#define LCD_RW                  DIO_enuPin2
#define LCD_Enable              DIO_enuPin3

#define LCD_ModeSelection           LCD_4bitMode
#define LCD_8bitMode                    0x38
#define LCD_4bitMode                    0x28


#define LCD_DisplayClear                0x01
#define LCD_FunctionSet                 0b00110000
#define LCD_DisplayOnOffCur            0x0C
#define LCD_EntryModeSet                0b00000110

#define LCD_Home                        0x02
#define LCD_AutoIncrementCur               0x06

#define LCD_Row0    0
#define LCD_Row1    1

#endif	/* LCD_CFG_H */

