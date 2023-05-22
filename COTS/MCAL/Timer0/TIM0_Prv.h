/* 
 * File:   TIM0_Prv.h
 * Author: alaa
 *
 * Created on March 2, 2023, 1:53 PM
 */

#ifndef TIM0_PRV_H
#define	TIM0_PRV_H

#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)
#define OCR0	*((volatile u8*)0x5C)
#define TCCR0	*((volatile u8*)0x53)
#define TCNT0	*((volatile u8*)0x52)


#define TOV0		0
#define OCF0		1
#define TOIE0		0
#define OCIE0		1
#endif	/* TIM0_PRV_H */

