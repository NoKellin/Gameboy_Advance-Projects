#include "main.h"
#include <cmath>
#include <vector>

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();
    change_bg_clr(BLACK);

    while (1)
    {
        // --- WAIT FOR NEW UPDATE ---
        vid_vsync();

        // --- REMOVE OLD INFO ---
        clear_screen();
        scan_keys();

        // --- UPDATE INFO ---

        // --- DRAW NEW INFO ---

        // --- SHOW NEW INFO ---
        vid_flip();
    }

    return 0;
}