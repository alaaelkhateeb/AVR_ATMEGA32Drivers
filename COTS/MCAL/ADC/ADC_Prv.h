/* 
 * File:   ADC_Prv.h
 * Author: alaa
 *
 * Created on February 9, 2023, 12:40 AM
 */

#ifndef ADC_PRV_H
#define	ADC_PRV_H
#define ADMUX   *((volatile u8*)(0x27))
#define ADCSRA  *((volatile u8*)(0x26))
#define ADCL    *((volatile u8*)(0x24))
#define ADCH    *((volatile u8*)(0x25))
#define SFIOR   *((volatile u8*)(0x50))

#define MUX0        0
#define MUX1        1
#define MUX2        2
#define MUX3        3
#define MUX4        4
#define ADLAR       5
#define REFS0       6
#define REFS1       7

#define ADPS0       0
#define ADPS1       1
#define ADPS2       2
#define ADIE        3
#define ADIF        4
#define ADATE       5
#define ADSC        6
#define ADEN        7



#endif	/* ADC_PRV_H */

