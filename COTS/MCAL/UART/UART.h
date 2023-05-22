/* 
 * File:   UART.h
 * Author: alaa
 *
 * Created on March 29, 2023, 2:08 AM
 */

#ifndef UART_H
#define	UART_H



#define  UART_ParityModeSelection    UART_ParityModeDisable
#define UART_ParityModeDisable   0
#define UART_ParityModeEven      2
#define UART_ParityModeOdd       3


#define  UART_StopBitSelection      UART_1StopBit
#define  UART_1StopBit              0
#define  UART_2StopBit              1

#define  UART_DataBitsSelection     UART_8DataBits
#define  UART_5DataBits             0
#define  UART_6DataBits             1
#define  UART_7DataBits             2
#define  UART_8DataBits             3
#define  UART_9DataBits             7

#define  UART_ClkPolaritySelection      UART_ClkRisingEdg
#define  UART_ClkRisingEdg          0
#define  UART_ClkFallingEdg         1



#define UART_BaudRate2400           207
#define UART_BaudRate4800           103
#define UART_BaudRate9600           51

typedef void (*UARTcbf_t)(void);
typedef enum {
    UART_enuOk = 0,
    UART_enuNotOk,
    UART_enuNullPtr,
    UART_enuTimeOut        
} UART_tenuErrorStatus;



void UART_Init(void);
UART_tenuErrorStatus UART_SendSyncData(u16 cpy_u16Data);
UART_tenuErrorStatus UART_RecieveSyncData(u16* Add_u16Data);
UART_tenuErrorStatus UART_SendASyncData(u16 cpy_u16Data);
UART_tenuErrorStatus UART_RecieveASyncData(u16* Add_u16Data);
UART_tenuErrorStatus UART_RegisterCallBackFunction(void(*UARTcbf_t)(void));
#endif	/* UART_H */

