#include "debug.h"
#include "timer.h"

char debug_fps[64];

extern bool logInitNoCash()
{
    for(unsigned int i = 0; i < 6; i++)
    {
        if("no$gba"[i] != NOCASH_SIG[i]) return false;
    }

    return true;
}

extern void logOutputNoCash(unsigned char level, const char* message)
{
    (void)level;
    while(*message)
    {
        REG_NOCASH_LOG = *message++;
    }

    REG_NOCASH_LOG = '\n';
}

void print_frames_per_second()
{
    if (REG_TM3D != get_seconds_elapsed())
    {
        set_seconds_elapsed(REG_TM3D);
        sprintf(debug_fps, "Time: %02d:%02d:%02d | Frames: %u | Cycles: %u", get_seconds_elapsed() / 3600, (get_seconds_elapsed() % 3600) / 60, get_seconds_elapsed() % 60, get_frame_count(), get_frame_cycles());
        logOutputNoCash(0, debug_fps);
        reset_frame_count();
    }
}