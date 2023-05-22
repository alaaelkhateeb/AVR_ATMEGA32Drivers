/*LIB Layer*/
#include "Std_types.h"
#include "Bit_math.h"

/*MCAL*/
#include "DIO.h"
#include "ExtInt.h"
#include "ExtInt_Cfg.h"
#include "ExtInt_Prv.h"

void ExtInt_Init() {
    u8 Loc_u8Temp = 0;
    /*checking enabling*/
#if ExtInt0_OnOff == ExtInt_enuEn
    SET_BIT(GICR, ExtInt_INT0);

        /**checking mode INT0*/
    #if ExtInt0_enuMode == ExtInt_LowLevel

         Loc_u8Temp=MCUCR;
         Loc_u8Temp &= ~(MaskBits);
		Loc_u8Temp |= Mode_LowLevel;
//        CLR_BIT(MCUCR, ISC00);
//        CLR_BIT(MCUCR, ISC01);

    #elif ExtInt0_Mode == ExtInt_enuAnyLogic
//        SET_BIT(MCUCR, ISC00);
//        CLR_BIT(MCUCR, ISC01);
        Loc_u8Temp=MCUCR;
        Loc_u8Temp &= ~(MaskBits);
		Loc_u8Temp |= Mode_AnyLogic;
    #elif ExtInt0_Mode == ExtInt_enuFalling
//        CLR_BIT(MCUCR, ISC00);
//         SET_BIT(MCUCR, ISC01);
        
        Loc_u8Temp=MCUCR;
        Loc_u8Temp &= ~(MaskBits);
		Loc_u8Temp |= Mode_FALLING_EDGE;
    #elif ExtInt0_Mode == ExtInt_enuRising
//        SET_BIT(MCUCR, ISC00);
//        SET_BIT(MCUCR, ISC01);
        Loc_u8Temp=MCUCR;
        Loc_u8Temp &= ~(MaskBits);
		Loc_u8Temp |= INT2Mode_RISING_EDGE;        
    #endif
#endif

#if ExtInt1_OnOff == ExtInt_enuEn
    SET_BIT(GICR, ExtInt_INT1);
    /**checking mode INT0*/
    #if ExtInt1_Mode == ExtInt_LowLevel

//        CLR_BIT(MCUCR, ISC10);
//            CLR_BIT(MCUCR, ISC11);
        Loc_u8Temp = MCUCR;
        Loc_u8Temp &= ~(MaskBits << 2);
        Loc_u8Temp |= (Mode_LowLevel << 2);

    #elif ExtInt1_Mode == ExtInt_enuAnyLogic
//        SET_BIT(MCUCR, ISC10);
//        CLR_BIT(MCUCR, ISC11);
        Loc_u8Temp = MCUCR;
        Loc_u8Temp &= ~(MaskBits << 2);
        Loc_u8Temp |= (Mode_AnyLogic << 2);
    #elif ExtInt1_Mode == ExtInt_enuFalling
//        CLR_BIT(MCUCR, ISC10);
//        SET_BIT(MCUCR, ISC11);
        Loc_u8Temp = MCUCR;
        Loc_u8Temp &= ~(MaskBits << 2);
        Loc_u8Temp |= (Mode_FALLING_EDGE << 2);
    #elif ExtInt1_Mode == ExtInt_enuRising
//        SET_BIT(MCUCR, ISC10);
//        SET_BIT(MCUCR, ISC11);
        Loc_u8Temp = MCUCR;
        Loc_u8Temp &= ~(MaskBits << 2);
        Loc_u8Temp |= (Mode_RISING_EDGE << 2);        
    #endif
#endif


#if ExtInt2_OnOff == ExtInt_enuEn
    SET_BIT(GICR, ExtInt_INT2);
        /**checking mode INT0*/
    #if ExtInt1_Mode == ExtInt_enuFalling

        CLR_BIT(MCUCSR, ISC2);
    #elif ExtInt1_Mode == ExtInt_enuRising

        SET_BIT(MCUCSR, ISC2);
    #endif

#endif




}

void ExtInt_Enable() {

}

void ExtInt_Disable() {
#if ExtInt0_OnOff == ExtInt_enuDisable
    CLR_BIT(GICR, ExtInt_INT0);

#endif

#if ExtInt1_OnOff == ExtInt_enuDisable
    CLR_BIT(GICR, ExtInt_INT1);

#endif

#if ExtInt2_OnOff == ExtInt_enuDisable
    CLR_BIT(GICR, ExtInt_INT2);

#endif

}