/* 
 * File:   SevenSegment_Cfg.h
 * Author: alaa
 *
 * Created on January 20, 2023, 3:07 PM
 */

#ifndef SEVENSEGMENT_CFG_H
#define	SEVENSEGMENT_CFG_H

#include "DIO.h"

typedef enum {
    CommonAnode = 0,
    CommonCathod
} SevenSeg_tenuModeStatus;

typedef struct {
    DIO_tenuPort PortNumber;
    SevenSeg_tenuModeStatus Mode;
} SevenSegStr_cfg_t;

typedef enum {
      SSeg0
    , SSeg1
    , SevenSeg_Numbers
} SevenSeg_tenuNumber;

extern const SevenSegStr_cfg_t SevenSeg_cfg[SevenSeg_Numbers];

#endif	/* SEVENSEGMENT_CFG_H */

