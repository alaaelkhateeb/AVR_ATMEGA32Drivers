/* 
 * File:   BTN_Cfg.h
 * Author: alaa
 *
 * Created on January 21, 2023, 11:29 PM
 */

#ifndef BTN_CFG_H
#define	BTN_CFG_H

typedef enum {
    BTN_Active_High = 0,
    BTN_Active_Low
} BTN_tenuModeStatus;

typedef enum {
       BTN0
    , BTN1
    , BTNs_Numbers
} BTN_tenuBTNNumber;

typedef struct {
    DIO_tenuPins PinNumber;
    DIO_tenuPort PortNumber;
    BTN_tenuModeStatus ActiveState;
} BTNStr_cfg_t;

extern const BTNStr_cfg_t BTN_Config[BTNs_Numbers];
#endif	/* BTN_CFG_H */

