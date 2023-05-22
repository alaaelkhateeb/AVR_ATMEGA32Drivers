/* 
 * File:   KeyPad.h
 * Author: alaa
 *
 * Created on February 3, 2023, 11:10 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

typedef enum {
    KeyPad_enu1 = 0,
    KeyPad_enu2,
    KeyPad_enu3,
    KeyPad_enu4,
    KeyPad_enu5,
    KeyPad_enu6,
    KeyPad_enu7,
    KeyPad_enu8,
    KeyPad_enu9,
    KeyPad_enu0,
    KeyPad_enuStar,
    KeyPad_enuHash,
#if (KeyPad_Size==KeyPad_4x4)
    KeyPad_enuA,
    KeyPad_enuB,
    KeyPad_enuC,
    KeyPad_enuD,

#endif
    KeyPad_enuNumberOfButton,
    KeyPad_enuNotPressed = 255
} KeyPad_tenuKeyPressed;

typedef enum {
    KeyPad_enuOk = 0,
    KeyPad_enuNotOk
} KeyPad_tenuErrorStatus;

KeyPad_tenuErrorStatus KeyPad_enuGetPressedKey(KeyPad_tenuKeyPressed* Add_PenuKeyPressed);

#endif	/* KEYPAD_H */

