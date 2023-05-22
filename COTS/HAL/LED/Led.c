#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "Led_Cfg.h"
#include "Led.h"

LED_tenuErrorStatus LED_enuLedON(LED_tenuLEDNumber Cpy_u8LED_Num) {

    LED_tenuErrorStatus Loc_enuStatus = LED_enuOk;
    /*checking if active high to set pin in port */
    if (LED_Confg[Cpy_u8LED_Num].ActiveState == Active_High) {
        Loc_enuStatus = DIO_enuSetPin(LED_Confg[Cpy_u8LED_Num].PortNumber, LED_Confg[Cpy_u8LED_Num].PinNumber);
        /*checking if active low to clear pin in port tobe set  */
    } else if (LED_Confg[Cpy_u8LED_Num].ActiveState == Active_Low) {
        Loc_enuStatus = DIO_enuClearPin(LED_Confg[Cpy_u8LED_Num].PortNumber, LED_Confg[Cpy_u8LED_Num].PinNumber);
    } else {
        Loc_enuStatus = LED_enuNotOk;
    }
    return Loc_enuStatus;
}

LED_tenuErrorStatus LED_enuLedOFF(LED_tenuLEDNumber Cpy_u8LED_Num) {
    LED_tenuErrorStatus Loc_enuStatus = LED_enuOk;
     /*checking if active high to clear pin in port */
    if (LED_Confg[Cpy_u8LED_Num].ActiveState == Active_High) {
        Loc_enuStatus = DIO_enuClearPin(LED_Confg[Cpy_u8LED_Num].PortNumber, LED_Confg[Cpy_u8LED_Num].PinNumber);
        /*checking if active low to set pin in port  */
    } else if (LED_Confg[Cpy_u8LED_Num].ActiveState == Active_Low) {
        Loc_enuStatus = DIO_enuSetPin(LED_Confg[Cpy_u8LED_Num].PortNumber, LED_Confg[Cpy_u8LED_Num].PinNumber);
    } else {
        Loc_enuStatus = LED_enuNotOk;
    }
    return Loc_enuStatus;
}
LED_tenuErrorStatus LED_enuLedToggle(LED_tenuLEDNumber Cpy_u8LED_Num) {
    LED_tenuErrorStatus Loc_enuStatus = LED_enuOk;
     /*checking if active high to clear pin in port */
    if (LED_Confg[Cpy_u8LED_Num].ActiveState == Active_High) {
        Loc_enuStatus = DIO_enuTogglePin(LED_Confg[Cpy_u8LED_Num].PortNumber, LED_Confg[Cpy_u8LED_Num].PinNumber);
        /*checking if active low to set pin in port  */
    } else if (LED_Confg[Cpy_u8LED_Num].ActiveState == Active_Low) {
        Loc_enuStatus = DIO_enuTogglePin(LED_Confg[Cpy_u8LED_Num].PortNumber, LED_Confg[Cpy_u8LED_Num].PinNumber);
    } else {
        Loc_enuStatus = LED_enuNotOk;
    }
    return Loc_enuStatus;
}