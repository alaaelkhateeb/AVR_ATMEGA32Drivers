
/*LIB Layer*/
#include "Std_types.h"
#include "Bit_math.h"

/*MCAL*/
#include "DIO.h"
#include "GlobalInt.h"
#include "GlobalInt_Cfg.h"
#include "GlobalInt_Prv.h"

void GlobalInt_enuEnable(){
    
    SET_BIT(SREG,GInt_BitEn);
    
}
void GlobalInt_enuDisable(){
    CLR_BIT(SREG,GInt_BitEn);
}