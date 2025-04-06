#include "main.h"

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();

    change_bg_clr(WHITE);

    int xpos = 0;

    while (1)
    {
        vid_vsync();
        clear_screen();
        xpos++;
        plot(xpos, 10, BLACK);
        vid_flip();
    }

    return 0;
}