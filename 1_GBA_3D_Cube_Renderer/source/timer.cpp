#include "timer.h"

static u32 sec = -1;
static u32 frames = 0;
 
static u32 prev_cycles = 0;
static u32 cycles = 0;

void start_all_timers()
{
    REG_TM0D = 0;
    REG_TM0CNT = TM_ENABLE;

    REG_TM1CNT = TM_ENABLE | TM_CASCADE;

    REG_TM2D = -0x4000;
    REG_TM2CNT = TM_FREQ_1024;
    REG_TM2CNT ^= TM_ENABLE;

    REG_TM3CNT = TM_ENABLE | TM_CASCADE;
}

void update_frame_timing()
{
    frames++;
    u32 curr_cycles = ((REG_TM1D << 16) | REG_TM0D);
    cycles = curr_cycles - prev_cycles;
    prev_cycles = curr_cycles;
}

u32 get_frame_cycles() { return cycles; }

void reset_frame_count() { frames = 0; }
u32 get_frame_count() { return frames; }

void set_seconds_elapsed(vu16 value) { sec = value; }
u32 get_seconds_elapsed() { return sec; }
