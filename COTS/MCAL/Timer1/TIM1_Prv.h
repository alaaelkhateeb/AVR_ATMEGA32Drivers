/* 
 * File:   TIM1_Prv.h
 * Author: alaa
 *
 * Created on April 12, 2023, 4:18 PM
 */

#ifndef TIM1_PRV_H
#define	TIM1_PRV_H

#define TIMSK            *((volatile u8*)0x59)
#define TIFR             *((volatile u8*)0x58)
#define TCCR1A           *((volatile u8*)0x4F)
#define TCCR1B           *((volatile u8*)0x4E)
#define TCNT1            *((volatile u16*)0x4C)
#define TCNT1H           *((volatile u8*)0x4D)
#define TCNT1L           *((volatile u8*)0x4C)
#define OCR1A            *((volatile u16*)0x4A)
#define OCR1AH           *((volatile u8*)0x4B)
#define OCR1AL           *((volatile u8*)0x4A)
#define OCR1B            *((volatile u16*)0x48)
#define OCR1BH           *((volatile u8*)0x49)
#define OCR1BL           *((volatile u8*)0x48)
#define ICR1             *((volatile u16*)0x46)
#define ICR1H            *((volatile u8*)0x47)
#define ICR1L            *((volatile u8*)0x46)


#define CS10             0
#define CS11             1
#define CS12             2
#define WGM12            3
#define WGM13            4

////////////////////////////////
#define WGM10            0
#define WGM11            1
#define FOC1B            2
#define FOC1A            3
#define COM1B0           4
#define COM1B1           5
#define COM1A0           6
#define COM1A1           7
///////////////


/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0


#define ICNC1   7
#define ICES1   6

#endif	/* TIM1_PRV_H */

