/*LIB Layer*/
#include "Std_types.h"
#include "Bit_math.h"

#include "Delay.h"


void delay_ms(double ms) {
    volatile double temp = 0;
    while (temp < ms) {
        temp += (0.275 / CLK_SPEED);
    }
}