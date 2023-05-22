#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "UART_Prv.h"
#include "UART.h"


static void(*MyISR)(void) = NULL;
#define ISR_IMP(ISR_No) void __vector_##ISR_No (void) __attribute__((signal));\
						void __vector_##ISR_No (void)
static u16 Glob_u16Data;
static u16* Glob_AddData;

void UART_Init(void) {

    UCSRC |= (1 << URSEL);
    UCSRC &= 0x80;
    /*Asynch mode*/
    UCSRC &= ~(1 << UMSEL);
    UCSRC |= (UART_ParityModeSelection << 4);
    UCSRC |= (UART_StopBitSelection << 3);
    UCSRC |= (UART_DataBitsSelection << 1);
    UCSRC |= (UART_ClkPolaritySelection << 0);

    /* Enable Int*/
    UCSRB |= (1 << 7) | (1 << 6);

    /**Enable Transmitter*/
    UCSRB |= (1 << TXEN);
    /**Enable Receiver*/
    UCSRB |= (1 << RXEN);


    UCSRC &= ~(1 << URSEL);
    UBRRL = UART_BaudRate9600; /* Load lower 8-bits of the baud rate */
    UBRRH = (UART_BaudRate9600 >> 8); /* Load upper 8-bits*/
}

UART_tenuErrorStatus UART_SendSyncData(u16 cpy_u16Data) {
    UART_tenuErrorStatus Loc_StatusErr = UART_enuOk;
    u16 Loc_u8TimeOut = 0xFFFF;
    /* Wait for empty transmit buffer */
    while (!(UCSRA & (1 << 5))) {
        if (Loc_u8TimeOut == 0) {
            Loc_StatusErr = UART_enuTimeOut;
            break;
        }
        Loc_u8TimeOut--;

    }
    if ((UCSRA & (1 << 5))) {
        UDR = cpy_u16Data;
    }
    return Loc_StatusErr;
}

UART_tenuErrorStatus UART_RecieveSyncData(u16* Add_u16Data) {
    UART_tenuErrorStatus Loc_StatusErr = UART_enuOk;
    u16 Loc_u8TimeOut = 0xFFFF;
    /* Wait till data is received */
    while ((UCSRA & (1 << 7)) == 0) {
        if (Loc_u8TimeOut == 0) {
            Loc_StatusErr = UART_enuTimeOut;
            break;
        }
        Loc_u8TimeOut--;
    }
    if ((UCSRA & (1 << 7))) {
        *Add_u16Data = UDR;
    }
    return Loc_StatusErr;
}

UART_tenuErrorStatus UART_RegisterCallBackFunction(void(*UARTcbf_t)(void)) {
    UART_tenuErrorStatus Loc_StatusErr = UART_enuOk;
    if (UARTcbf_t) {
        MyISR = UARTcbf_t;
    } else {
        Loc_StatusErr = UART_enuNullPtr;
    }
    return Loc_StatusErr;
}

UART_tenuErrorStatus UART_SendASyncData(u16 cpy_u16Data) {
    UART_tenuErrorStatus Loc_StatusErr = UART_enuOk;
    Glob_u16Data = cpy_u16Data;
    return Loc_StatusErr;
}

UART_tenuErrorStatus UART_RecieveASyncData(u16* Add_u16Data) {
    UART_tenuErrorStatus Loc_StatusErr = UART_enuOk;
    Glob_AddData = Add_u16Data;
    return Loc_StatusErr;
}

/*data is empty*/
ISR_IMP(14) {
    *Glob_AddData = UDR;
}

/*RX complete*/
ISR_IMP(13) {
    UDR = Glob_u16Data;
}

/*TX complete*/
ISR_IMP(15) {

}