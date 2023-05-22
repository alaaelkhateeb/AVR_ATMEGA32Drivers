/**************************************************/
/*DIO HEADER FILE*/
/**************************************************/


#ifndef	DIO_H
#define DIO_H\

#include "Std_types.h"
#define DIO_MaxPinPerPort 8

#define DIO_DIR_OUTPUT	1
#define DIO_DIR_INPUT	0

#define DIO_INPUT_PULL_UP	0
#define DIO_INPUT_PULL_DOWN	1

typedef enum {
    DIO_enuOk = 0,
    DIO_enuNotOk,
    DIO_enuNullPtr
} DIO_tenuErrorStatus;

typedef enum {
    DIO_enuPin0 = 0,
    DIO_enuPin1,
    DIO_enuPin2,
    DIO_enuPin3,
    DIO_enuPin4,
    DIO_enuPin5,
    DIO_enuPin6,
    DIO_enuPin7,
    DIO_enuPin8,
    DIO_enuPin9,
    DIO_enuPin10,
    DIO_enuPin11,
    DIO_enuPin12,
    DIO_enuPin13,
    DIO_enuPin14,
    DIO_enuPin15,
    DIO_enuPin16,
    DIO_enuPin17,
    DIO_enuPin18,
    DIO_enuPin19,
    DIO_enuPin20,
    DIO_enuPin21,
    DIO_enuPin22,
    DIO_enuPin23,
    DIO_enuPin24,
    DIO_enuPin25,
    DIO_enuPin26,
    DIO_enuPin27,
    DIO_enuPin28,
    DIO_enuPin29,
    DIO_enuPin30,
    DIO_enuPin31,
    DIO_enuNumberOfPins
} DIO_tenuPins;

typedef enum {
    DIO_enuLow = 0,
    DIO_enuHigh
} DIO_tenuPinValue;

typedef enum {
    DIO_PORTA = 0,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD,
    DIO_enuNumberOfPorts
} DIO_tenuPort;
/**************************************************/
/*DIO init function
    Input:void
    output:DIO_tenuErrorStatus to report errors*/
/**************************************************/
DIO_tenuErrorStatus DIO_enuInit(void);


/**************************************************/
/*DIO_enuSetPin
    Input:	Cpy_u8DIO_Port
			Cpy_u8PinNumber(Range from 0 ->31)
    output:DIO_tenuErrorStatus to report errors*/
/**************************************************/
DIO_tenuErrorStatus DIO_enuSetPinValue(DIO_tenuPort Cpy_u8DIO_Port, DIO_tenuPins Cpy_u8DIO_Pinnum, DIO_tenuPinValue Cpy_tenuPinVal);

/**************************************************/
/*DIO_enuClearPin
    Input:Cpy_u8PinNumber(Range from 0 ->31)
    output:DIO_tenuErrorStatus to report errors*/
/**************************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPort Cpy_u8DIO_Port, DIO_tenuPins Cpy_u8DIO_Pinnum);
/**************************************************/
/*DIO_enuClearPin
    Input:Cpy_u8DIO_Port
			Cpy_u8PinNumber(Range from 0 ->31)
    output:DIO_tenuErrorStatus to report errors*/
/**************************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPort Cpy_u8DIO_Port, DIO_tenuPins Cpy_u8DIO_Pinnum);



/**************************************************/
/*DIO_enuGetPin
    Input:Cpy_u8DIO_Port
			Cpy_u8PinNumber(Range from 0 ->31)
			Add_u8PinValue
    output:DIO_tenuErrorStatus to report errors*/
/**************************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPort Cpy_u8DIO_Port, DIO_tenuPins Cpy_enuPinNumber, u8* Add_u8PinValue);

/**************************************************/
/*DIO_enuSetPortValue
    Input:Cpy_u8DIO_Port
			Cpy_tenuPortVal
    output:DIO_tenuErrorStatus to report errors*/
DIO_tenuErrorStatus DIO_enuSetPortValue(DIO_tenuPort Cpy_u8DIO_Port,  u8 Cpy_tenuPortVal) ;
/**************************************************/
/*DIO_enuSetPort
    Input:Cpy_u8DIO_Port
    output:DIO_tenuErrorStatus to report errors*/
DIO_tenuErrorStatus DIO_enuSetPort(DIO_tenuPort Cpy_u8DIO_Port);












#endif/*DIO_H*/