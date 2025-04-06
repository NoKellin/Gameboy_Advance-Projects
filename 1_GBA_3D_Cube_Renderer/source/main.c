#include <main.h>
#include <debug.h>

COLOR *vid_page = vid_mem_back;

COLOR *vid_flip(){
    vid_page = (COLOR*)((u32)vid_page ^ VRAM_PAGE_SIZE);
    REG_DISPCNT ^= DCNT_PAGE;

    return vid_page;
}

int main()
{
    REG_DISPCNT= DCNT_MODE4 | DCNT_BG2;

    int ii = 0;
    char msg[120];

    while(1){
        vid_vsync();

        if(++ii == 60){
            ii = 0;
            sprintf(msg, "%08X", REG_DISPCNT);
            logOutputNoCash(0, msg);
            vid_flip();
        }
    }

    return 0;
}