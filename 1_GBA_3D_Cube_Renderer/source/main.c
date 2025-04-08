#include "main.h"

char key[32];

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
        xpos++;
        
        if(xpos > SCREEN_WIDTH) xpos = 0;
        
        sprintf(key, "key %04X is pressed", curr_key_input);
        if(get_key(KEY_START) && get_key_up(KEY_B)){
            logOutputNoCash(0, key);
        }
        
        // --- DRAW NEW INFO ---        
        plot(xpos, 10, BLACK);

        // --- SHOW NEW INFO ---
        vid_flip();
    }

    return 0;
}