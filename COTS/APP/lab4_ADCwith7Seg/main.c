/*
 * File:   main.c
 * Author: alaa
 *
 * Created on February 9, 2023, 1:09 AM
 */

#include "util/delay.h"
#include "DIO.h"
#include "SevenSegment.h"

#include "ADC.h"

int main(void) {
    DIO_enuInit();
   volatile u16 Loc_u8Data = 0;
    volatile u8 value;
    ADC_enuInit();

    while (1) {
        ADC_enuGetADCValue(ADC_enuChannel1, &Loc_u8Data);
        Loc_u8Data = (Loc_u8Data * 0.0488);
       Loc_u8Data = (Loc_u8Data * 99)/50;
        if (Loc_u8Data >= 0 && Loc_u8Data <= 9) {
            value = (u8) Loc_u8Data;
            SevenSeg_enuDisplay(0, value);
            SevenSeg_enuDisplay(1, 0);
        } else {
            value = (u8) (Loc_u8Data % 10);
            SevenSeg_enuDisplay(0, value);
             value = (u8) (Loc_u8Data / 10);
            SevenSeg_enuDisplay(1, value);
        }
        _delay_ms(500);
    }
}