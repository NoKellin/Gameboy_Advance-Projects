#include "debug.h"

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

void print_frames_per_second(char *text, vu16 timer_data, u32 &sec, u32 &frames)
{
    if (timer_data != sec)
    {
        sec = timer_data;
        sprintf(text, "Time: %02d:%02d:%02d | Frames: %u", sec / 3600, (sec % 3600) / 60, sec % 60, frames);
        logOutputNoCash(0, text);
        frames = 0;
    }
}