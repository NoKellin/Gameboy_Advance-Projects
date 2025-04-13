#include "main.h"

char ts[32];
char cy[32];

#define REG_TM0D    *(vu16*)(REG_BASE + 0x0100)
#define REG_TM0CNT  *(vu16*)(REG_BASE + 0x0102)

#define REG_TM1D    *(vu16*)(REG_BASE + 0x0104)
#define REG_TM1CNT    *(vu16*)(REG_BASE + 0x0106)

#define TM_FREQ_1   0x0000

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();
    change_bg_clr(BLACK);

    REG_TM0D = 0;
    REG_TM0CNT = TM_ENABLE;

    REG_TM1CNT = TM_ENABLE | TM_CASCADE;

    // REG_TM2D = -0x4000;
    // REG_TM2CNT = TM_FREQ_1024;
    // REG_TM2CNT ^= TM_ENABLE;

    // REG_TM3CNT = TM_ENABLE | TM_CASCADE;

    u32 sec = -1;
    u32 frames = 0;

    u32 prev_cycles = 0;

    while (1)
    {
        // --- WAIT FOR NEW UPDATE ---
        vid_vsync();
        frames++;

        // --- REMOVE OLD INFO ---
        clear_screen();
        scan_keys();

        // --- UPDATE INFO ---

        u32 curr_cycles = ((REG_TM1D << 16) | REG_TM0D);
        u32 delta_cycles = curr_cycles - prev_cycles;
        prev_cycles = curr_cycles;

        sprintf(cy, "Cycles: %u", delta_cycles);
        logOutputNoCash(0, cy);

        // print_frames_per_second(ts, REG_TM3D, sec, frames);

        // --- DRAW NEW INFO ---

        // --- SHOW NEW INFO ---
        vid_flip();
    }

    return 0;
}