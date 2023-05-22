#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "BTN.h"
#include "BTN_Cfg.h"

BTN_tenuErrorStatus BTN_enuIsPressed(BTN_tenuBTNNumber Cpy_u8DIO_Pinnum, u8* Add_u8PinValue) {
    BTN_tenuErrorStatus Loc_enuStatus = BTN_enuOk;
    /**read push button value for pin in port*/
     Loc_enuStatus = DIO_enuGetPin(BTN_Config[Cpy_u8DIO_Pinnum].PortNumber, BTN_Config[Cpy_u8DIO_Pinnum].PinNumber, Add_u8PinValue);
    
    
    return Loc_enuStatus;

}