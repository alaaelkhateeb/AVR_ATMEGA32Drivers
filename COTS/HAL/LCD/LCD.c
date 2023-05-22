
#include <util/delay.h>
#include <stdlib.h>

#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "LCD.h"
#include "LCD_Cfg.h"
#include "LCD_Prv.h"

LCD_tenuErrorStatus LCD_Init() {
    LCD_tenuErrorStatus Loc_enuStatus = LCD_enuOk;

    DIO_enuSetPinValue(LCD_CtrlPort_Selection, LCD_RW, DIO_enuLow);
    //sending on
    LCD_WriteCommand(LCD_DisplayClear); /* clear display */
    _delay_ms(30);
#if LCD_ModeSelection ==LCD_8bitMode
    LCD_WriteCommand(LCD_8bitMode); /* Initialization of 16X2 LCD in 8bit mode */
#elif LCD_ModeSelection ==LCD_4bitMode
    LCD_WriteCommand(LCD_4bitMode); /* Initialization of 16X2 LCD in 4bit mode */
#endif
    LCD_WriteCommand(LCD_DisplayOnOffCur); /* Display ON Cursor OFF */
    LCD_WriteCommand(LCD_Home);

    LCD_WriteCommand(LCD_AutoIncrementCur); /* Auto Increment cursor */
    LCD_WriteCommand(LCD_DisplayClear); /* clear display */
    DIO_enuSetPinValue(LCD_CtrlPort_Selection, LCD_RS, DIO_enuLow);


    return Loc_enuStatus;
}

LCD_tenuErrorStatus LCD_WriteData(u8 cpy_u8Data) {
    LCD_tenuErrorStatus Loc_enuStatus = LCD_enuOk;
    ////RS is ON sending data
    DIO_enuSetPinValue(LCD_CtrlPort_Selection, LCD_RS, DIO_enuHigh);
    DIO_enuSetPinValue(LCD_CtrlPort_Selection, LCD_RW, DIO_enuLow);
    _delay_us(1);
#if LCD_ModeSelection ==LCD_8bitMode
    DIO_enuSetPortValue(LCD_DataPort_Selection, cpy_u8Data);
#elif LCD_ModeSelection ==LCD_4bitMode
    DIO_enuSetPortValue(LCD_HalfDataPort_Selection, cpy_u8Data & 0xF0);
    LCD_vidEnable();
    _delay_ms(10);
    DIO_enuSetPortValue(LCD_HalfDataPort_Selection, cpy_u8Data << 4);

#endif


    LCD_vidEnable();
    _delay_ms(10);
    return Loc_enuStatus;
}

LCD_tenuErrorStatus LCD_WriteCommand(u8 cpy_u8Command) {
    LCD_tenuErrorStatus Loc_enuStatus = LCD_enuOk;
    ////RS is OFF sending command
    DIO_enuSetPinValue(LCD_CtrlPort_Selection, LCD_RS, DIO_enuLow);
    DIO_enuSetPinValue(LCD_CtrlPort_Selection, LCD_RW, DIO_enuLow);

#if LCD_ModeSelection ==LCD_8bitMode
    DIO_enuSetPortValue(LCD_DataPort_Selection, cpy_u8Command);
#elif LCD_ModeSelection ==LCD_4bitMode
    DIO_enuSetPortValue(LCD_HalfDataPort_Selection, cpy_u8Command & 0xF0);
    LCD_vidEnable();
    _delay_ms(10);
    DIO_enuSetPortValue(LCD_HalfDataPort_Selection, cpy_u8Command << 4);

#endif
    LCD_vidEnable();
    _delay_ms(10);
    return Loc_enuStatus;
}

LCD_tenuErrorStatus LCD_GoToXY(u8 cpy_u8X, u8 cpy_u8Y) {
    LCD_tenuErrorStatus Loc_enuStatus = LCD_enuOk;
    u8 Loc_u8FinalPos = 0;
    switch (cpy_u8X) {
        case LCD_Row0:
            Loc_u8FinalPos = 0x00 + cpy_u8Y;
            break;
        case LCD_Row1:
            Loc_u8FinalPos = 0x40 + cpy_u8Y;
            break;
    }
    LCD_WriteCommand(Loc_u8FinalPos | LCD_DDRAM_ADD);
    return Loc_enuStatus;
}

LCD_tenuErrorStatus LCD_DisplaySpecialChar(u8* Add_u8Pattern, u8 cpy_u8Block, u8 cpy_u8X, u8 cpy_u8Y) {
    LCD_tenuErrorStatus Loc_enuStatus = LCD_enuOk;
    /**to get which address in CG*/
    u8 Loc_u8Address = cpy_u8Block * BlockSize;
    LCD_WriteCommand(Loc_u8Address | LCD_CGRAM_ADD);
    for (u8 Loc_u8Counter = 0; Loc_u8Counter < 8; Loc_u8Counter++) {
        LCD_WriteData(Add_u8Pattern[Loc_u8Counter]);
    }
    LCD_WriteCommand(LCD_DDRAM_ADD);
    LCD_GoToXY(cpy_u8X, cpy_u8Y);
    LCD_WriteData(cpy_u8Block);
    return Loc_enuStatus;
}

LCD_tenuErrorStatus LCD_WriteString(u8* Add_u8String) {
    LCD_tenuErrorStatus Loc_enuStatus = LCD_enuOk;
    for (u8 Loc_u8Counter = 0; Add_u8String[Loc_u8Counter] != '\0'; Loc_u8Counter++) {
        LCD_WriteData(Add_u8String[Loc_u8Counter]);
    }
    return Loc_enuStatus;
}

LCD_tenuErrorStatus LCD_WriteNumber(u16 cpy_u8Num) {
    LCD_tenuErrorStatus Loc_enuStatus = LCD_enuOk;
    char buffer[11];
    itoa(cpy_u8Num, buffer, 10);
    LCD_WriteString(buffer);
    return Loc_enuStatus;
}

void LCD_vidEnable(void) {
    DIO_enuSetPinValue(LCD_CtrlPort_Selection, LCD_Enable, DIO_enuHigh);
    _delay_ms(1);
    DIO_enuSetPinValue(LCD_CtrlPort_Selection, LCD_Enable, DIO_enuLow);
}