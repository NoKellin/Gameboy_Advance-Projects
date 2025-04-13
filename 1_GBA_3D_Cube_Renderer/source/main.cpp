#include "main.h"

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    start_all_timers();
    setup_vid_base_pal();
    change_bg_clr(BLACK);

    while (1)
    {
        // --- WAIT FOR NEW UPDATE ---
        vid_vsync();
        update_frame_timing();

        // --- REMOVE OLD INFO ---
        clear_screen();
        scan_keys();

        // --- UPDATE INFO ---

        // --- DRAW NEW INFO ---
        
        // --- SHOW NEW INFO ---
        print_frames_per_second();
        vid_flip();
    }

    return 0;
}