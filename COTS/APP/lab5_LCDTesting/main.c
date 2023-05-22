/*
 * File:   main.c
 * Author: alaa
 *
 * Created on February 2, 2023, 3:14 PM
 */
#include "util/delay.h"
#include "DIO.h"
#include "Led.h"
#include "BTN.h"
#include "Delay.h"
#include "SevenSegment.h"
#include "KeyPad.h"
#include "ExtInt.h"
#include "GlobalInt.h"
#include "DIO_prv.h"
#include "ADC.h"
#include "LCD.h"
#include "LCD_Cfg.h"

int main(void) {
    DIO_enuInit();
    _delay_ms(20);
u8 Loc_string1[]=" Finallly LOO is ";	
u8 Loc_string2[]=" here ^-^";	
    LCD_Init();


    while (1) {
        LCD_WriteString(Loc_string1);
        LCD_GoToXY(LCD_Row1,0);
        LCD_WriteString(Loc_string2);
        LCD_WriteNumber(43);
        _delay_ms(1000);
        LCD_WriteCommand(LCD_DisplayClear);
       
    }
}