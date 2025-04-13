#include "main.h"

#define REG_TM2D *(vu16 *)(REG_BASE + 0x0108)
#define REG_TM2CNT *(vu16 *)(REG_BASE + 0x010A)

#define REG_TM3D *(vu16 *)(REG_BASE + 0x010C)
#define REG_TM3CNT *(vu16 *)(REG_BASE + 0x010E)

#define TM_CASCADE 0x0004
#define TM_FREQ_1024 0x0003
#define TM_ENABLE 0x0080

char ts[32];

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();
    change_bg_clr(BLACK);

    REG_TM2D = -0x4000;
    REG_TM2CNT = TM_FREQ_1024;

    REG_TM3CNT = TM_ENABLE | TM_CASCADE;

    u32 sec = -1;

    while (1)
    {
        // --- WAIT FOR NEW UPDATE ---
        vid_vsync();

        // --- REMOVE OLD INFO ---
        clear_screen();
        scan_keys();

        // --- UPDATE INFO ---

        if (REG_TM3D != sec)
        {
            sec = REG_TM3D;
            sprintf(ts, "%02d:%02d:%02d", sec / 3600, (sec % 3600) / 60, sec % 60);
            logOutputNoCash(0, ts);
        }

        if (get_key_down(KEY_START))
        {
            REG_TM2CNT ^= TM_ENABLE;
        }

        // --- DRAW NEW INFO ---

        // --- SHOW NEW INFO ---
        // vid_flip();
    }

    return 0;
}