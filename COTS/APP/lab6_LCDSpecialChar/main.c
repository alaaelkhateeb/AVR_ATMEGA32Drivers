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


    u8 customChar0[] = {
        0b1010,
        0b0101,
        0b0100,
        0b0100,
        0b0100,
        0b0100,
        0b0100,
        0b0100
    };

    u8 customChar1[] = {
        0b0101,
        0b0101,
        0b0101,
        0b0101,
        0b0101,
        0b0101,
        0b0101,
        0b1111
    };
    u8 customChar2[] = {
        0b0000,
        0b0000,
        0b0000,
        0b0111,
        0b1000,
        0b0110,
        0b0001,
        0b1111
    };
    DIO_enuInit();
    _delay_ms(20);
    LCD_Init();


    while (1) {
        LCD_DisplaySpecialChar(customChar0, 0, 1, 3);
        LCD_DisplaySpecialChar(customChar1, 1, 1, 2);
        LCD_DisplaySpecialChar(customChar2, 2, 1, 1);

        _delay_ms(8000);
        LCD_WriteCommand(LCD_DisplayClear);
        _delay_ms(6000);
    }
}