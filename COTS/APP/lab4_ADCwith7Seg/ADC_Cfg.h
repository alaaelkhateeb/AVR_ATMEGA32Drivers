/* 
 * File:   ADC_Cfg.h
 * Author: alaa
 *
 * Created on February 9, 2023, 12:40 AM
 */

#ifndef ADC_CFG_H
#define	ADC_CFG_H

#define ADC_RefSourceSelection  ADC_AVCC
#define ADC_AREF                 (0b00)
#define ADC_AVCC                 (0b01)
#define ADC_Internal_256         (0b11)


#define ADC_Enable ADC_ON
#define ADC_ON  1
#define ADC_OFF 0

#define ADC_AUTO_TRIGER_ENABLE      0

#define ADC_INT_ENABLE          0

#define ADC_PRESCLAR_SELECTION      ADC_enuPreDiv64
#define ADC_enuPreDiv2                (0b000)
#define	ADC_enuPreDiv2again           (0b001)
#define	ADC_enuPreDiv4                (0b010)
#define	ADC_enuPreDiv8                (0b011)
#define	ADC_enuPreDiv16               (0b100)
#define	ADC_enuPreDiv32               (0b101)
#define	ADC_enuPreDiv64               (0b110)
#define	ADC_enuPreDiv128              (0b111)


#define ADC_AdjustSelection ADC_RightAdjust
#define ADC_LeftAdjust 1
#define ADC_RightAdjust 0


#define ADC_ADMUX_CLR_Mask (0b00111111)
#endif	/* ADC_CFG_H */

