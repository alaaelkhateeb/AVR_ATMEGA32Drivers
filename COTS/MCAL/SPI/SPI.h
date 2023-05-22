/* 
 * File:   SPI.h
 * Author: alaa
 *
 * Created on April 4, 2023, 9:52 PM
 */

#ifndef SPI_H
#define	SPI_H

typedef enum {
    SPI_enuOk = 0,
    SPI_enuNotOk,
    SPI_enuNullPtr,
    SPI_enuTimeOut
} SPI_tenuErrorStatus;



#define SPI_IntEnable 0b10000000


#define SPI_DataOrderSelection      SPI_DataOrderLsbFirst
#define SPI_DataOrderMask           0b11011111
#define SPI_DataOrderLsbFirst       0b00100000
#define SPI_DataOrderMsbFirst       0b00000000



#define SPI_MasterSlaveMask     0b11101111
#define SPI_MasterSelect        0b00010000
#define SPI_SlaveSelect         0b00000000

#define SPI_ClkPolaritySelection        SPI_ClkPolarityRis
#define SPI_ClkPolarityMask         0b11110111
#define SPI_ClkPolarityRisLead      0b00001000
#define SPI_ClkPolarityFallLead     0b00000000

#define SPI_ClkPhaseSelection        SPI_ClkPolarityRis
#define SPI_ClkPhaseMask            0b11111011
#define SPI_ClkPPhaseSetupLead      0b00000100
#define SPI_ClkPhaseSampleLead      0b00000000

#define SPI_ClkRateSelect   SPI_ClkRateDiv64
#define SPI_ClkRateMask              0b11111100
#define SPI_ClkRateDiv4                 0
#define SPI_ClkRateDiv16                1 
#define SPI_ClkRateDiv64                2
#define SPI_ClkRateDiv128 				3
#define SPI_ClkRateDiv2   				4
#define SPI_ClkRateDiv8   				5
#define SPI_ClkRateDiv32  				6
#define SPI_ClkRateDiv64  				7


void SPI_MasterInit(void);
SPI_tenuErrorStatus SPI_TransmitData(u8 data);
SPI_tenuErrorStatus SPI_ReceiveData(u8* Add_u8Data);

void SPI_SlaveInit(void);

#endif	/* SPI_H */

