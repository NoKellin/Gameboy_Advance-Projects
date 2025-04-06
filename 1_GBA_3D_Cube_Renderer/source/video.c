#include <video.h>

COLOR *vid_page = vid_mem_back;

void vid_vsync()
{
	while(REG_VCOUNT >= 160);	// wait till VDraw
	while(REG_VCOUNT < 160);	// wait till VBlank
}

void clear_screen()
{
    u16 fill = 0x0000;
    u16 *dst = (u16 *)vid_page;
    int count = (240 * 160);
    for (int i = 0; i < count; i++)
    {
        dst[i] = fill;
    }
}

COLOR *vid_flip()
{
    vid_page = (COLOR *)((u32)vid_page ^ VRAM_PAGE_SIZE);
    REG_DISPCNT ^= DCNT_PAGE;

    return vid_page;
}