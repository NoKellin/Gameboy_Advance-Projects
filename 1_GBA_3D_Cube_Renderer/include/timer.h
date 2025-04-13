#ifndef TIMER_H
#define TIMER_H

#include "types.h"
#include "memory.h"

#define REG_TM0D        *(vu16*)(REG_BASE + 0x0100)
#define REG_TM0CNT      *(vu16*)(REG_BASE + 0x0102)

#define REG_TM1D        *(vu16*)(REG_BASE + 0x0104)
#define REG_TM1CNT      *(vu16*)(REG_BASE + 0x0106)

#define REG_TM2D        *(vu16 *)(REG_BASE + 0x0108)
#define REG_TM2CNT      *(vu16 *)(REG_BASE + 0x010A)

#define REG_TM3D        *(vu16 *)(REG_BASE + 0x010C)
#define REG_TM3CNT      *(vu16 *)(REG_BASE + 0x010E)

#define TM_FREQ_1       0x0000
#define TM_CASCADE      0x0004
#define TM_FREQ_1024    0x0003
#define TM_ENABLE       0x0080

void start_all_timers();
void update_frame_timing();

u32 get_frame_cycles();

void reset_frame_count();
u32 get_frame_count();

void set_seconds_elapsed(vu16 data);
u32 get_seconds_elapsed();

#endif