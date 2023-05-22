/*
 * File:   main.c
 * Author: alaa
 *
 * Created on January 18, 2023, 12:52 PM
 */


#define F_CPU 1000000UL
#include "util/delay.h"
#include "DIO.h"
#include "Led.h"
#include "BTN.h"

int main(void) {
    
    DIO_enuInit();
    u8 Loc_u8RetrunedValue = 0;
    u8 Loc_u8RetrunedValue1 = 0;
    DIO_tenuPort Loc_enuPortA = DIO_PORTA;
    DIO_tenuPort Loc_enuPortB = DIO_PORTB;
    volatile u8 count = 0;
    while (1) {
        BTN_enuIsPressed(Loc_enuPortB, 8, &Loc_u8RetrunedValue);
        BTN_enuIsPressed(Loc_enuPortB, 9, &Loc_u8RetrunedValue1);
        if (!Loc_u8RetrunedValue && count < 8) {
            _delay_ms(100); /*debouncing of switch*/
            LED_enuLedON(Loc_enuPortA, count);
            count++;
        }
        if (!Loc_u8RetrunedValue1 && 0 < count) {
            count--;
            _delay_ms(100); /*debouncing of switch*/
            LED_enuLedOFF(Loc_enuPortA, count);
        }
    }
}