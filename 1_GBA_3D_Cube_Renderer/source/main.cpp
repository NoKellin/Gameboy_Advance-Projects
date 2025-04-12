#include "main.h"

char y[32];

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();

    change_bg_clr(WHITE);

    int yPos = 40;

    while (1)
    {
        // --- WAIT FOR NEW UPDATE ---
        vid_vsync();
        
        // --- REMOVE OLD INFO ---
        clear_screen();
        scan_keys();

        // --- UPDATE INFO ---

        // --- DRAW NEW INFO ---

        if(get_key(KEY_DOWN)){
            yPos++;
            sprintf(y, "%d", yPos);
            logOutputNoCash(0,y);
        }
        else if(get_key(KEY_UP)){
            yPos--;
            sprintf(y, "%d", yPos);
            logOutputNoCash(0,y);
        }

        // draw_line(30, yPos, 60, yPos, GREEN);
        plot(30, yPos, RED);

        // --- SHOW NEW INFO ---
        vid_flip();
    }

    return 0;
}