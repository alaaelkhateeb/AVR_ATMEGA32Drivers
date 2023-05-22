/*
 * File:   main.c
 * Author: alaa
 *
 * Created on 17 ?????, 2023, 10:01 ?
 */


#define F_CPU 16000000UL
#include "util/delay.h"
#include "DIO.h"
#include "Led.h"

int main(void) {
    DIO_enuInit();
    volatile u8 count = 0;
    while (1) {


        DIO_tenuPort Loc_enuPortA = DIO_PORTA;
        if (count < 8) {

            LED_enuLedON(DIO_PORTA, count);
            _delay_ms(1000);
            LED_enuLedOFF(DIO_PORTA, count);
            count++;
        } else{
            count = 6;
            while(count){
                LED_enuLedON(Loc_enuPortA, count);
                _delay_ms(1000);
                LED_enuLedOFF(DIO_PORTA, count);
                count--;
            }
        }
    }
}