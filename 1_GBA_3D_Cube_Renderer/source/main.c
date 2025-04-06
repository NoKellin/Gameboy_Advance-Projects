#include "main.h"

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();

    add_vid_pal(15, 150, 120);
    add_vid_pal(150, 50, 120);

    int xpos = 0;

    while (1)
    {
        vid_vsync();
        clear_screen();
        xpos++;
        plot(xpos, 10, GREEN);
        vid_flip();
    }

    return 0;
}