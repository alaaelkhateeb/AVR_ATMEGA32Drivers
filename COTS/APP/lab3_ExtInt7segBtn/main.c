/*
 * File:   main.c
 * Author: alaa
 *
 * Created on February 2, 2023, 3:14 PM
 */
#include "util/delay.h"
#include<avr/interrupt.h>
#include "DIO.h"
#include "Led.h"
#include "BTN.h"
#include "Delay.h"
#include "SevenSegment.h"
#include "KeyPad.h"
#include "ExtInt.h"
#include "GlobalInt.h"
#include "DIO_prv.h"

s8 Glob_s8Counter = 0;

ISR(INT0_vect) {

    Glob_s8Counter++;
    if (Glob_s8Counter > 9) {
        Glob_s8Counter = 9;
    }

    SevenSeg_enuDisplay(0, Glob_s8Counter);
}

ISR(INT1_vect) {

    Glob_s8Counter--;
    if (Glob_s8Counter < 0) {
        Glob_s8Counter = 0;
    }

    SevenSeg_enuDisplay(0, Glob_s8Counter);
}

int main(void) {
    DIO_enuInit();
    GlobalInt_enuEnable();
    ExtInt_Init();
        while (1) {

    }
}