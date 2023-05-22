/**
 ******************************************************************************
 * @file    DIO.c
 * @author  Alaa Elkhateeb
 * @brief   all the functions implementation for DIO.
 * @date    JAN 17, 2022
 ******************************************************************************
 */
/*LIB Layer*/
#include "Std_types.h"
#include "Bit_math.h"

/*MCAL*/
#include "DIO.h"
#include "DIO_Cfg.h"
#include "DIO_prv.h"


DIO_tenuErrorStatus DIO_enuInit(void) {
    u8 count;
    u8 Loc_u8PortNumber = 0;
    u8 Loc_u8PinNumber = 0;
    for (count = 0; count < DIO_enuNumberOfPins; count++) {
        Loc_u8PortNumber = count / DIO_MaxPinPerPort;
        Loc_u8PinNumber = count % DIO_MaxPinPerPort;
        switch (Loc_u8PortNumber) {
            case(DIO_PORTA):
                if (DIO_strPinCfg[count].DIO_PinDirection == DIO_DIR_OUTPUT) {
                    SET_BIT(DDRA, Loc_u8PinNumber);
                } else {
                    CLR_BIT(DDRA, Loc_u8PinNumber);
                    if (DIO_strPinCfg[count].DIO_InputStatus == DIO_INPUT_PULL_UP) {
                        SET_BIT(PORTA, Loc_u8PinNumber);
                    }
                }
                break;
            case(DIO_PORTB):
                if (DIO_strPinCfg[count].DIO_PinDirection == DIO_DIR_OUTPUT) {
                    SET_BIT(DDRB, Loc_u8PinNumber);
                } else {
                    CLR_BIT(DDRB, Loc_u8PinNumber);
                    if (DIO_strPinCfg[count].DIO_InputStatus == DIO_INPUT_PULL_UP) {
                        SET_BIT(PORTB, Loc_u8PinNumber);
                    }
                }
                break;
            case(DIO_PORTC):
                if (DIO_strPinCfg[count].DIO_PinDirection == DIO_DIR_OUTPUT) {
                    SET_BIT(DDRC, Loc_u8PinNumber);
                } else {
                    CLR_BIT(DDRC, Loc_u8PinNumber);
                    if (DIO_strPinCfg[count].DIO_InputStatus == DIO_INPUT_PULL_UP) {
                        SET_BIT(PORTC, Loc_u8PinNumber);
                    }
                }
                break;
            case(DIO_PORTD):
                if (DIO_strPinCfg[count].DIO_PinDirection == DIO_DIR_OUTPUT) {
                    SET_BIT(DDRD, Loc_u8PinNumber);
                } else {
                    CLR_BIT(DDRD, Loc_u8PinNumber);
                    if (DIO_strPinCfg[count].DIO_InputStatus == DIO_INPUT_PULL_UP) {
                        SET_BIT(PORTD, Loc_u8PinNumber);
                    }
                }
                break;
        }
    }


    return DIO_enuOk;
}

DIO_tenuErrorStatus DIO_enuSetPinValue(DIO_tenuPort Cpy_u8DIO_Port, DIO_tenuPins Cpy_u8DIO_Pinnum, DIO_tenuPinValue Cpy_tenuPinVal) {


    DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
    u8 Loc_u8PinNumber = 0;
    Loc_u8PinNumber = Cpy_u8DIO_Pinnum % DIO_MaxPinPerPort;
    if (Cpy_u8DIO_Port > DIO_enuNumberOfPorts) {
        Loc_enuStatus = DIO_enuNotOk;
    } else if (Loc_u8PinNumber > DIO_enuNumberOfPins) {
        Loc_enuStatus = DIO_enuNotOk;
    } else if ((Cpy_tenuPinVal != DIO_enuHigh) && (Cpy_tenuPinVal != DIO_enuLow)) {
        Loc_enuStatus = DIO_enuNotOk;
    } else {
        switch (Cpy_u8DIO_Port) {
            case DIO_PORTA:
                if (Cpy_tenuPinVal == DIO_enuHigh) {
                    SET_BIT(PORTA, Loc_u8PinNumber);
                } else {
                    CLR_BIT(PORTA, Loc_u8PinNumber);
                }
                break;
            case DIO_PORTB:
                if (Cpy_tenuPinVal == DIO_enuHigh) {
                    SET_BIT(PORTB, Loc_u8PinNumber);
                } else {
                    CLR_BIT(PORTB, Loc_u8PinNumber);
                }
                break;
            case DIO_PORTC:
                if (Cpy_tenuPinVal == DIO_enuHigh) {
                    SET_BIT(PORTC, Loc_u8PinNumber);
                } else {
                    CLR_BIT(PORTC, Loc_u8PinNumber);
                }
                break;
            case DIO_PORTD:
                if (Cpy_tenuPinVal == DIO_enuHigh) {
                    SET_BIT(PORTD, Loc_u8PinNumber);
                } else {
                    CLR_BIT(PORTD, Loc_u8PinNumber);
                }
                break;
            default:
                Loc_enuStatus = DIO_enuNotOk;
                break;

        }
    }
    return Loc_enuStatus;
}

DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPort Cpy_u8DIO_Port, DIO_tenuPins Cpy_u8DIO_Pinnum) {

    DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
    u8 Loc_u8PinNumber = 0;
    Loc_u8PinNumber = Cpy_u8DIO_Pinnum % DIO_MaxPinPerPort;
    if (Cpy_u8DIO_Port > DIO_enuNumberOfPorts) {
        Loc_enuStatus = DIO_enuNotOk;
    } else if (Cpy_u8DIO_Pinnum > DIO_enuNumberOfPins) {
        Loc_enuStatus = DIO_enuNotOk;
    } else {
        switch (Cpy_u8DIO_Port) {
            case DIO_PORTA:
                SET_BIT(PORTA, Loc_u8PinNumber);
                break;
            case DIO_PORTB:
                SET_BIT(PORTB, Loc_u8PinNumber);
                break;
            case DIO_PORTC:
                SET_BIT(PORTC, Loc_u8PinNumber);
                break;
            case DIO_PORTD:
                SET_BIT(PORTD, Loc_u8PinNumber);
                break;
            default:
                Loc_enuStatus = DIO_enuNotOk;
                break;
        }
    }
    return Loc_enuStatus;
}

DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPort Cpy_u8DIO_Port, DIO_tenuPins Cpy_u8DIO_Pinnum) {

    DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
    u8 Loc_u8PinNumber = 0;
    Loc_u8PinNumber = Cpy_u8DIO_Pinnum % DIO_MaxPinPerPort;
    if (Cpy_u8DIO_Port > DIO_enuNumberOfPorts) {
        Loc_enuStatus = DIO_enuNotOk;
    } else if (Cpy_u8DIO_Pinnum > DIO_enuNumberOfPins) {
        Loc_enuStatus = DIO_enuNotOk;
    } else {
        switch (Cpy_u8DIO_Port) {
            case DIO_PORTA:
                CLR_BIT(PORTA, Loc_u8PinNumber);
                break;
            case DIO_PORTB:
                CLR_BIT(PORTB, Loc_u8PinNumber);
                break;
            case DIO_PORTC:
                CLR_BIT(PORTC, Loc_u8PinNumber);
                break;
            case DIO_PORTD:
                CLR_BIT(PORTD, Loc_u8PinNumber);
                break;
            default:
                Loc_enuStatus = DIO_enuNotOk;
                break;

        }
    }
    return Loc_enuStatus;
}

DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPort Cpy_u8DIO_Port, DIO_tenuPins Cpy_enuPinNumber, u8* Add_u8PinValue) {

    DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
    u8 Loc_u8PinNumber = 0;
    Loc_u8PinNumber = Cpy_enuPinNumber % DIO_MaxPinPerPort;
    if (Cpy_u8DIO_Port > DIO_enuNumberOfPorts) {
        Loc_enuStatus = DIO_enuNotOk;
    } else if (Cpy_enuPinNumber > DIO_enuNumberOfPins) {
        Loc_enuStatus = DIO_enuNotOk;
    } else if (Add_u8PinValue == NULL) {
        Loc_enuStatus = DIO_enuNullPtr;

    } else {
        switch (Cpy_u8DIO_Port) {
            case DIO_PORTA:
                *Add_u8PinValue = GET_BIT(PINA, Loc_u8PinNumber);
                break;
            case DIO_PORTB:
                *Add_u8PinValue = GET_BIT(PINB, Loc_u8PinNumber);
                break;
            case DIO_PORTC:
                *Add_u8PinValue = GET_BIT(PINC, Loc_u8PinNumber);
                break;
            case DIO_PORTD:
                *Add_u8PinValue = GET_BIT(PIND, Loc_u8PinNumber);
                break;
            default:
                Loc_enuStatus = DIO_enuNotOk;
                break;

        }

    }
    return Loc_enuStatus;
}

DIO_tenuErrorStatus DIO_enuSetPortValue(DIO_tenuPort Cpy_u8DIO_Port, u8 Cpy_tenuPortVal) {
    DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
    if (Cpy_u8DIO_Port > DIO_enuNumberOfPorts) {
        Loc_enuStatus = DIO_enuNotOk;
    } else {
        switch (Cpy_u8DIO_Port) {
            case DIO_PORTA:
                ASSIGN_REG(PORTA, Cpy_tenuPortVal);
                break;
            case DIO_PORTB:
                ASSIGN_REG(PORTB, Cpy_tenuPortVal);
                break;
            case DIO_PORTC:
                ASSIGN_REG(PORTC, Cpy_tenuPortVal);
                break;
            case DIO_PORTD:
                ASSIGN_REG(PORTD, Cpy_tenuPortVal);
                break;
            default:
                Loc_enuStatus = DIO_enuNotOk;
                break;

        }

    }
    return Loc_enuStatus;

}
DIO_tenuErrorStatus DIO_enuSetPort(DIO_tenuPort Cpy_u8DIO_Port){
      DIO_tenuErrorStatus Loc_enuStatus = DIO_enuOk;
    if (Cpy_u8DIO_Port > DIO_enuNumberOfPorts) {
        Loc_enuStatus = DIO_enuNotOk;
    } else {
        switch (Cpy_u8DIO_Port) {
            case DIO_PORTA:
                SET_REG(PORTA);
                break;
            case DIO_PORTB:
                SET_REG(PORTB);
                break;
            case DIO_PORTC:
                SET_REG(PORTC);
                break;
            case DIO_PORTD:
                SET_REG(PORTD);
                break;
            default:
                Loc_enuStatus = DIO_enuNotOk;
                break;

        }

    }
    return Loc_enuStatus;
}