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
#include "UART.h"
#include "SPI.h"
#include <avr/interrupt.h>
#define F_CPU   8000000UL

//void Test(void) {
//    LED_enuLedToggle(LED3);
//    LED_enuLedToggle(LED0);
//}

int main(void) {

    u8 data = 0;
    DIO_enuInit();

    UART_Init();
    ;
    while (1) {
        //        UART_RecieveSyncData(&data);
        UART_SendSyncData(data++);


    }
}