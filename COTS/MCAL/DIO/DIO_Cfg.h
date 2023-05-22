/*************************************************/
/*DIO CONFIGURATION FILE*/
/**************************************************/


#ifndef	DIO_CFG_H
#define DIO_CFG_H


typedef struct{
	u8 DIO_PinDirection;
	u8 DIO_InputStatus;
}DIO_strPinCfg_t;

extern const DIO_strPinCfg_t DIO_strPinCfg[32];


#endif/*DIO_CFG_H*/