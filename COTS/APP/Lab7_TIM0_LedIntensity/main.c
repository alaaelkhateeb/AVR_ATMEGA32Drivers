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
#include "TIM0.h"
#include "TIM0_Prv.h"
#include <avr/interrupt.h>
#define F_CPU   8000000UL

void Test(void) {
    LED_enuLedToggle(LED0);

}

int main(void) {

    u8 Loc_u8RetrunedValue = 0, Loc_u8RetrunedValue1 = 0, Loc_u8DutyCycle = 100;
    DIO_enuInit();
    TIM0_vidInit();
    GlobalInt_enuEnable();
    //    TIM0_enuSetTickTimeMS(1000, 8);
    //    TIM0_enuRegisterCallback(&Test);




    while (1) {
        BTN_enuIsPressed(0, &Loc_u8RetrunedValue);
        BTN_enuIsPressed(1, &Loc_u8RetrunedValue1);
        if (!Loc_u8RetrunedValue) {
            Loc_u8DutyCycle -= 10;
        }
        if (!Loc_u8RetrunedValue1) {
            Loc_u8DutyCycle += 10;
        }
        TIM0_enuGeneratePWM(Loc_u8DutyCycle);
        TIM0_enuStart();
        if (Loc_u8DutyCycle < 0) {
            Loc_u8DutyCycle = 100;
        } else if (Loc_u8DutyCycle > 100) {
            Loc_u8DutyCycle = 100;
        }
    }
}