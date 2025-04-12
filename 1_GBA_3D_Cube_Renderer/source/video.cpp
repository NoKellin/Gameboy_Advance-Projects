#include "video.h"
#include "draw.h"

COLOR *vid_page = vid_mem_back;

void vid_vsync()
{
	while(REG_VCOUNT >= SCREEN_HEIGHT);	// wait till VDraw
	while(REG_VCOUNT < SCREEN_HEIGHT);	// wait till VBlank
}

void clear_screen()
{
    M4_CLEAR();
}

COLOR *vid_flip()
{
    vid_page = (COLOR *)((u32)vid_page ^ VRAM_PAGE_SIZE);
    REG_DISPCNT ^= DCNT_PAGE;

    return vid_page;
}