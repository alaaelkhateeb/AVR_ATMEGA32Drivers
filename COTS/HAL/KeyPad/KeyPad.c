/*LIB Layer*/

#include "Std_types.h"
#include "Bit_math.h"
#include <util/delay.h>
/*MCAL*/
#include "DIO.h"
#include "KeyPad.h"
#include "KeyPad_Cfg.h"
#include "KeyPad_Prv.h"


#define NumberOfRows    4
#if(KeyPad_Size==KeyPad_4x4)
#define NumberOfColumn      4
#endif
#if (KeyPad_State ==KeyPad_InputPullUP)
KeyPad_tenuErrorStatus KeyPad_enuGetPressedKey(KeyPad_tenuKeyPressed* Add_PenuKeyPressed) {
    u8 Loc_u8ReturnedValue = 0;
    KeyPad_tenuKeyPressed Loc_KeyValue = KeyPad_enuNotPressed;


    KeyPad_vidActivateRow(KeyPad_Row1);
    DIO_enuGetPin(DIO_PORTA, KeyPad_col1, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu1;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col2, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu2;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col3, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu3;
    }
#if (KeyPad_Size==KeyPad_4x4)
    DIO_enuGetPin(DIO_PORTA, KeyPad_col4, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enuA;
    }
#endif
    _delay_ms(5);
    KeyPad_vidActivateRow(KeyPad_Row2);
    DIO_enuGetPin(DIO_PORTA, KeyPad_col1, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu4;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col2, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu5;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col3, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu6;
    }
#if (KeyPad_Size==KeyPad_4x4)
    DIO_enuGetPin(DIO_PORTA, KeyPad_col4, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enuB;
    }
#endif
    _delay_ms(5);


    KeyPad_vidActivateRow(KeyPad_Row3);
    DIO_enuGetPin(DIO_PORTA, KeyPad_col1, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu7;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col2, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu8;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col3, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enu9;
    }
#if (KeyPad_Size==KeyPad_4x4)
    DIO_enuGetPin(DIO_PORTA, KeyPad_col4, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuLow) {
        Loc_KeyValue = KeyPad_enuC;
    }
#endif
    _delay_ms(5);
}

void KeyPad_vidActivateRow(u8 cpy_u8RowNumber) {
    DIO_enuSetPinValue(DIO_PORTA, KeyPad_Row1, DIO_enuHigh);
    DIO_enuSetPinValue(DIO_PORTA, KeyPad_Row2, DIO_enuHigh);
    DIO_enuSetPinValue(DIO_PORTA, KeyPad_Row3, DIO_enuHigh);
    DIO_enuSetPinValue(DIO_PORTA, KeyPad_Row4, DIO_enuHigh);
    DIO_enuSetPinValue(DIO_PORTA, cpy_u8RowNumber, DIO_enuLow);
}
#endif

#if (KeyPad_State ==KeyPad_InputPullDown)
KeyPad_tenuErrorStatus KeyPad_enuGetPressedKey(KeyPad_tenuKeyPressed* Add_PenuKeyPressed) {
    u8 Loc_u8ReturnedValue = 0;
    KeyPad_tenuKeyPressed Loc_KeyValue = KeyPad_enuNotPressed;


    KeyPad_vidActivateRow(KeyPad_Row1);
    DIO_enuGetPin(DIO_PORTA, KeyPad_col1, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu1;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col2, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu2;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col3, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu3;
    }
#if (KeyPad_Size==KeyPad_4x4)
    DIO_enuGetPin(DIO_PORTA, KeyPad_col4, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enuA;
    }
#endif
    _delay_ms(5);
    KeyPad_vidActivateRow(KeyPad_Row2);
    DIO_enuGetPin(DIO_PORTA, KeyPad_col1, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu4;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col2, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu5;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col3, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu6;
    }
#if (KeyPad_Size==KeyPad_4x4)
    DIO_enuGetPin(DIO_PORTA, KeyPad_col4, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enuB;
    }
#endif
    _delay_ms(5);


    KeyPad_vidActivateRow(KeyPad_Row3);
    DIO_enuGetPin(DIO_PORTA, KeyPad_col1, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu7;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col2, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu8;
    }
    DIO_enuGetPin(DIO_PORTA, KeyPad_col3, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enu9;
    }
#if (KeyPad_Size==KeyPad_4x4)
    DIO_enuGetPin(DIO_PORTA, KeyPad_col4, &Loc_u8ReturnedValue);
    if (Loc_u8ReturnedValue == DIO_enuHigh) {
        Loc_KeyValue = KeyPad_enuC;
    }
#endif
    _delay_ms(5);
}

void KeyPad_vidActivateRow(u8 cpy_u8RowNumber) {
    DIO_enuSetPinValue(DIO_PORTA, KeyPad_Row1, DIO_enuLow);
    DIO_enuSetPinValue(DIO_PORTA, KeyPad_Row2, DIO_enuLow);
    DIO_enuSetPinValue(DIO_PORTA, KeyPad_Row3, DIO_enuLow);
    DIO_enuSetPinValue(DIO_PORTA, KeyPad_Row4, DIO_enuLow);
    DIO_enuSetPinValue(DIO_PORTA, cpy_u8RowNumber, DIO_enuHigh);
}
#endif