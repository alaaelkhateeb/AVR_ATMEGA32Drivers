/* 
 * File:   ExtInt-Prv.h
 * Author: alaa
 *
 * Created on January 27, 2023, 10:16 AM
 */

#ifndef EXTINT_PRV_H
#define	EXTINT_PRV_H


#define GICR           *((volatile u8*)(0x5B))
#define GIFR           *((volatile u8*)(0x5A))
#define MCUCR          *((volatile u8*)(0x55))
#define MCUCSR          *((volatile u8*)(0x54))


#define ISC2	6
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

#define Mode_RISING_EDGE	0b11
#define Mode_FALLING_EDGE	0b10
#define Mode_LowLevel		0b00
#define Mode_AnyLogic		0b01
#define INT2Mode_RISING_EDGE 0b1
#define INT2Mode_FALLING_EDGE 0b0
#define MaskBits 0b11

#endif	/* EXTINT_PRV_H */

