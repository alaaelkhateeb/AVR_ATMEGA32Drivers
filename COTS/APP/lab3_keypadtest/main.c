/*
 * File:   main.c
 * Author: alaa
 *
 * Created on February 5, 2023, 6:11 PM
 */

#include "util/delay.h"
#include<avr/interrupt.h>
#include "DIO.h"
#include "KeyPad.h"
#include "DIO_prv.h"

int main(void) {
    DIO_enuInit();
    u8 loc_u8Key = 0;
    while (1) {
        KeyPad_enuGetPressedKey(&loc_u8Key);
        if (loc_u8Key == KeyPad_enu2) {
            DIO_enuSetPinValue(DIO_PORTB, DIO_enuPin1, DIO_enuHigh);
            _delay_ms(500);
        } else {
            DIO_enuSetPinValue(DIO_PORTB, DIO_enuPin1, DIO_enuLow);

        }

    }
}
