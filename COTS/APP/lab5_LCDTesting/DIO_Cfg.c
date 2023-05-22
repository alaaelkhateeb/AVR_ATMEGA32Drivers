/*LIB Layer*/
#include "Std_types.h"
#include "Bit_math.h"

/*MCAL*/

#include "DIO_Cfg.h"
#include "DIO.h"

const DIO_strPinCfg_t DIO_strPinCfg[32]=
{/******************PORTA********************/
		   /*PIN DIRECTION*//*PULLUP PULL DOWN*/
/**PIN0**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN1**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN2**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN3**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN4**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN5**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN6**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN7**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},

/******************PORTB********************/
/**PIN8**/ {DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN9**/ {DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN10**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN11**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN12**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN13**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN14**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN15**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/******************PORTC********************/
/**PIN16**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_DOWN},
/**PIN17**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_DOWN},
/**PIN18**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_DOWN},
/**PIN19**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_DOWN},
/**PIN20**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_DOWN},
/**PIN21**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_DOWN},
/**PIN22**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_DOWN},
/**PIN23**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_DOWN},
/******************PORTD********************/
/**PIN24**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN25**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN26**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN27**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN28**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN29**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN30**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP},
/**PIN31**/{DIO_DIR_OUTPUT,DIO_INPUT_PULL_UP}
};