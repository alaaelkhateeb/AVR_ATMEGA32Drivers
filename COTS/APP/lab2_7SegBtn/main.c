/*
 * File:   main.c
 * Author: alaa
 *
 * Created on January 20, 2023, 4:28 PM
 */


#define F_CPU 16000000UL
#include "util/delay.h"
#include "DIO.h"
#include "Led.h"
#include "BTN.h"
#include "Delay.h"
#include "SevenSegment.h"

int main(void) {
    DIO_enuInit();
    u8 Loc_u8Counter0 = 0, Loc_u8Counter1 = 0;
    u8 Loc_u8RetrunedValue = 0;
    while (1) {
        BTN_enuIsPressed(0, &Loc_u8RetrunedValue);
        if (!Loc_u8RetrunedValue) {
            Loc_u8Counter0++;
            if (Loc_u8Counter0 > 10) {
                Loc_u8Counter0 = 0;
                Loc_u8Counter1++;
                if (Loc_u8Counter1 > 10) {
                    Loc_u8Counter1 = 0;
                }

            }
            SevenSeg_enuDisplay(SSeg0, Loc_u8Counter0);
            _delay_ms(500);
            SevenSeg_enuDisplay(SSeg1, Loc_u8Counter1);
            _delay_ms(500);
        }
    }
}