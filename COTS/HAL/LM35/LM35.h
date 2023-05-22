/* 
 * File:   LM35.h
 * Author: alaa
 *
 * Created on February 14, 2023, 11:49 PM
 */

#ifndef LM35_H
#define	LM35_H

void LM35_vidInit(void);
void LM35_vidGetReading(ADC_tenuChannels ADC_ChSelect,u16* Add_Pu16Value);

#endif	/* LM35_H */

