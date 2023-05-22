/* 
 * File:   GlobalInt.h
 * Author: alaa
 *
 * Created on January 27, 2023, 10:13 AM
 */

#ifndef GLOBALINT_H
#define	GLOBALINT_H

typedef enum {
    GInt_enuOk = 0,
    GInt_enuNotOk
} GInt_tenuErrorStatus;


void GlobalInt_enuEnable();
void GlobalInt_enuDisable();
#endif	/* GLOBALINT_H */

