/* 
 * File:   Led_Cfg.h
 * Author: alaa
 *
 * Created on January 20, 2023, 3:10 PM
 */

#ifndef LED_CFG_H
#define	LED_CFG_H

typedef enum {
    Active_High = 0,
    Active_Low
} LED_tenuModeStatus;

typedef enum {
    LED0
    , LED1
    , LED2
    , LED3
    , LED4
    , LED5
    , LED6
    , LED7
    , LEDs_Numbers
} LED_tenuLEDNumber;

typedef struct {
    DIO_tenuPins PinNumber;
    DIO_tenuPort PortNumber;
    LED_tenuModeStatus ActiveState;
} LED_strCfg_t;

extern const LED_strCfg_t LED_Confg[LEDs_Numbers];
#endif	/* LED_CFG_H */

