#include "Std_types.h"
#include "Bit_math.h"


#include "DIO.h"
#include "SevenSegment.h"
#include "SevenSegment_Cfg.h"


 const u8 SevenSeg_arrNumbers[10] = {
    SSegNumber0,
    SSegNumber1,
    SSegNumber2,
    SSegNumber3,
    SSegNumber4,
    SSegNumber5,
    SSegNumber6,
    SSegNumber7,
    SSegNumber8,
    SSegNumber9
};
SevenSeg_tenuErrorStatus SevenSeg_enuDisplay(SevenSeg_tenuNumber SSeg_number,u8 Cpy_u8Data) {
    SevenSeg_tenuErrorStatus Loc_enuStatus = SevenSeg_enuOk;
    if (SevenSeg_cfg[SSeg_number].Mode == CommonAnode) {
        Loc_enuStatus = DIO_enuSetPortValue(SevenSeg_cfg[SSeg_number].PortNumber,~SevenSeg_arrNumbers[Cpy_u8Data]);
    } else {
        Loc_enuStatus = DIO_enuSetPortValue(SevenSeg_cfg[SSeg_number].PortNumber, SevenSeg_arrNumbers[Cpy_u8Data]);
    }

    return Loc_enuStatus;
}


