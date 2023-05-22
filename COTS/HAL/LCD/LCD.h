/* 
 * File:   LCD.h
 * Author: alaa
 *
 * Created on February 10, 2023, 2:04 PM
 */

#ifndef LCD_H
#define	LCD_H

#define LCD_DDRAM_ADD		0x80
#define LCD_CGRAM_ADD		0x40

#define BlockSize				8
typedef enum {
    LCD_enuOk = 0,
    LCD_enuNotOk,
    LCD_enuNullPtr
} LCD_tenuErrorStatus;

LCD_tenuErrorStatus LCD_Init();
LCD_tenuErrorStatus LCD_WriteData(u8 cpy_u8Data);
LCD_tenuErrorStatus LCD_WriteCommand(u8 cpy_u8Command);
LCD_tenuErrorStatus LCD_GoToXY(u8 cpy_u8X,u8 cpy_u8Y);
LCD_tenuErrorStatus LCD_DisplaySpecialChar(u8* Add_u8Pattern,u8 cpy_u8Block,u8 cpy_u8X,u8 cpy_u8Y);
LCD_tenuErrorStatus LCD_WriteString(u8* Add_u8String);
LCD_tenuErrorStatus LCD_WriteNumber(u16 cpy_u8Num);
void LCD_vidEnable(void);
#endif	/* LCD_H */

