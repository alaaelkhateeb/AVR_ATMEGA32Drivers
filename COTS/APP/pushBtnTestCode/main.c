/*
 * File:   main.c
 * Author: alaa
 *
 * Created on January 20, 2023, 4:28 PM
 */


#define F_CPU 1000000UL
#include "util/delay.h"
#include "DIO.h"
#include "Led.h"
#include "BTN.h"
#include "Delay.h"

int main(void) {
    DIO_enuInit();
    u8 Loc_u8RetrunedValue = 0;
    while (1) {
        LED_enuLedON(0);
        BTN_enuIsPressed(0, &Loc_u8RetrunedValue);
        if (!Loc_u8RetrunedValue) {
            LED_enuLedOFF(0);
            _delay_ms(1000);
          
        }
    }
}