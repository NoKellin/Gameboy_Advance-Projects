#include "main.h"

char ts[32];

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();
    change_bg_clr(BLACK);

    REG_TM2D = -0x4000;
    REG_TM2CNT = TM_FREQ_1024;
    REG_TM2CNT ^= TM_ENABLE;

    REG_TM3CNT = TM_ENABLE | TM_CASCADE;

    u32 sec = -1;
    u32 frames = 0;

    while (1)
    {
        // --- WAIT FOR NEW UPDATE ---
        vid_vsync();
        frames++;

        // --- REMOVE OLD INFO ---
        clear_screen();
        scan_keys();

        // --- UPDATE INFO ---

        print_frames_per_second(ts, REG_TM3D, sec, frames);

        // --- DRAW NEW INFO ---

        // --- SHOW NEW INFO ---
        vid_flip();
    }

    return 0;
}