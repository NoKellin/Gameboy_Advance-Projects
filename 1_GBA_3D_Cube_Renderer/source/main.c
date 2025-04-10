#include "main.h"

char position[32];

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();

    change_bg_clr(WHITE);

    int xpos = 0;

    while (1)
    {
        // --- WAIT FOR NEW UPDATE ---
        vid_vsync();

        // --- REMOVE OLD INFO ---
        clear_screen();
        scan_keys();
        
        // --- UPDATE INFO ---
        if(get_key_down(KEY_LEFT))
        {
            xpos--;
            if(xpos < 0) xpos = SCREEN_WIDTH - 1;

            sprintf(position, "position: %d", xpos);
            logOutputNoCash(0, position);

        }
        else if(get_key_down(KEY_RIGHT)) 
        {
            xpos++;
            if(xpos > SCREEN_WIDTH - 1) xpos = 0;

            sprintf(position, "position: %d", xpos);
            logOutputNoCash(0, position);
        }
        

        // --- DRAW NEW INFO ---        
        plot(xpos, 10, BLACK);

        // --- SHOW NEW INFO ---
        vid_flip();
    }

    return 0;
}