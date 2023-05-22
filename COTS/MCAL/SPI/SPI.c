#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "SPI_Prv.h"
#include "SPI.h"

void SPI_MasterInit(void) {
    /* Set MOSI and SCK output,others input */

    SPCR &= SPI_DataOrderMask;
    SPCR |= SPI_DataOrderSelection;

    SPCR |= SPI_IntEnable;

    SPCR &= SPI_MasterSlaveMask;
    SPCR |= SPI_MasterSelect;

    SPCR &= SPI_ClkPolarityMask;
    SPCR |= SPI_ClkPolaritySelection;

    SPCR &= SPI_ClkPhaseSelection;
    SPCR |= SPI_MasterSelect;

    SPCR &= SPI_ClkRateMask;
    SPCR |= (SPI_ClkRateSelect << 0);

    //    if (SPI_ClkRateSelect < 4) {
    //        SPSR &= ~(1 << 0);
    //    } else if (SPI_ClkRateSelect > 3) {
    //        SPSR |= (1 << 0);
    //    }
}

SPI_tenuErrorStatus SPI_TransmitData(u8 data) {
    SPI_tenuErrorStatus Loc_StatusErr = SPI_enuNotOk;
    u8 Loc_u8Temp;
    u16 Loc_u8TimeOut = 0xFFFF;

    ///* Start transmission */
    SPDR = data;
    /* Wait for transmission complete */

    while (!(SPSR & (1 << 7))) {
        if (Loc_u8TimeOut == 0) {
            Loc_StatusErr = SPI_enuTimeOut;
            break;
        }
        Loc_u8TimeOut--;

    }
    if ((SPSR & (1 << 7))) {
        /*to clear flag*/
        Loc_u8Temp = SPDR;
    }
    return Loc_StatusErr;
}

SPI_tenuErrorStatus SPI_ReceiveData(u8* Add_u8Data) {
    SPI_tenuErrorStatus Loc_StatusErr = SPI_enuNotOk;
    u8 Loc_u8Temp;
    u16 Loc_u8TimeOut = 0xFFFF;

    /* Wait for transmission complete */

    while (!(SPSR & (1 << 7))) {
        if (Loc_u8TimeOut == 0) {
            Loc_StatusErr = SPI_enuTimeOut;
            break;
        }
        Loc_u8TimeOut--;

    }
    if ((SPSR & (1 << 7))) {
        *Add_u8Data = SPDR;
    }
    return Loc_StatusErr;
}

void SPI_SlaveInit(void) {
    /* Set MISO output, all others input */
    SPCR &= SPI_ClkPhaseSelection;
    SPCR |= SPI_SlaveSelect;

}

