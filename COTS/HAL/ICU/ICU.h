/* 
 * File:   ICU.h
 * Author: alaa
 *
 * Created on April 12, 2023, 10:03 PM
 */

#ifndef ICU_H
#define	ICU_H

#define  ICU_Falling            0
#define  ICU_Rising             1

#define ICU_PrescalerSelection ICU_ClkDiv8
#define  ICU_EdgSelection ICU_Falling

#define  CpuFreq1            8000000UL
#define ICU_PREClrMask  0b11111000
#define  ICU_StopTIM       0b11111000


#define   ICU_NoClkSrc      	 0
#define   ICU_Clk				 1
#define   ICU_ClkDiv8       	 2
#define   ICU_ClkDiv64      	 3
#define   ICU_ClkDiv256		     4
#define   ICU_ClkDiv1024		 5
#define   ICU_EXTPinFalling      6
#define   ICU_EXTPinrising       7



typedef enum {
    ICU_enuOk,
    ICU_enuNok,
    ICU_enuNullPtr,
    ICU_enuWrongValue
} ICU_enuErrorStatus_t;



void ICU_vidInit(void);

ICU_enuErrorStatus_t ICU_enuEdgeSelect(u8 Cpy_u8Edge);

ICU_enuErrorStatus_t ICU_enuMesureSignal(u8* Add_u8Freq, u8* Add_u8Duty);

ICU_enuErrorStatus_t ICU_enuGetCount(u32* Add_pu32Count);

#endif	/* ICU_H */

