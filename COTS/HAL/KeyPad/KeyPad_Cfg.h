/* 
 * File:   KeyPad_Cfg.h
 * Author: alaa
 *
 * Created on February 3, 2023, 11:10 AM
 */

#ifndef KEYPAD_CFG_H
#define	KEYPAD_CFG_H

#define KeyPad_4x3  0
#define KeyPad_4x4  1

/*options for size 4x3 or 4x4*/
#define KeyPad_Size     KeyPad_4x3


/**state of input pins*/
#define KeyPad_InputPullUP  0
#define KeyPad_InputPullDown  1
#define KeyPad_State  KeyPad_InputPullUP 


/***row configured as  OUTPUT*/
#define KeyPad_Row1 DIO_enuPin0
#define KeyPad_Row2 DIO_enuPin1
#define KeyPad_Row3 DIO_enuPin2
#define KeyPad_Row4 DIO_enuPin3

/**coulmn configured as input*/

#define KeyPad_col1 DIO_enuPin4
#define KeyPad_col2 DIO_enuPin5
#define KeyPad_col3 DIO_enuPin6

#if (KeyPad_Size==KeyPad_4x4)
    #define KeyPad_col4 DIO_enuPIN7
#endif

#endif	/* KEYPAD_CFG_H */

