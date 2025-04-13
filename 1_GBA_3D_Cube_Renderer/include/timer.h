#ifndef TIMER_H
#define TIMER_H

#include "types.h"
#include "memory.h"

#define REG_TM2D *(vu16 *)(REG_BASE + 0x0108)
#define REG_TM2CNT *(vu16 *)(REG_BASE + 0x010A)

#define REG_TM3D *(vu16 *)(REG_BASE + 0x010C)
#define REG_TM3CNT *(vu16 *)(REG_BASE + 0x010E)

#define TM_CASCADE 0x0004
#define TM_FREQ_1024 0x0003
#define TM_ENABLE 0x0080

#endif