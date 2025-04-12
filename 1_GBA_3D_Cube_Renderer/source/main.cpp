#include "main.h"

char y[32];

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();

    change_bg_clr(GRAY);

    int xPos = 30;
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
        }
        else if(get_key(KEY_UP)){
            yPos--;
        }

        if(get_key(KEY_LEFT)){
            xPos--;
        }
        else if(get_key(KEY_RIGHT)){
            xPos++;
        }

        draw_line(xPos, 30, 60, yPos, GREEN);
        // plot(30, yPos, RED);

        // --- SHOW NEW INFO ---
        vid_flip();
    }

    return 0;
}