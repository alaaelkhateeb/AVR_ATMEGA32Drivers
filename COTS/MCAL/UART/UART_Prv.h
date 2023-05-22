/* 
 * File:   UART_Prv.h
 * Author: alaa
 *
 * Created on March 29, 2023, 2:08 AM
 */

#ifndef UART_PRV_H
#define	UART_PRV_H

#define UDR    *((volatile u8*)0x2C)
#define UCSRA  *((volatile u8*)0x2B)
#define UCSRB  *((volatile u8*)0x2A)
#define UCSRC  *((volatile u8*)0x40)
#define UBRRL  *((volatile u8*)0x29)
#define UBRRH  *((volatile u8*)0x40)




#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN   4
#define TXEN   3



#define URSEL   7
#define UMSEL   6




#endif	/* UART_PRV_H */

