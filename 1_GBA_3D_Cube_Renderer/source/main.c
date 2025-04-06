#include <main.h>
#include <debug.h>

COLOR *vid_page = vid_mem_back;

static COLOR RGB8(u8 red, u8 green, u8 blue)
{
    return (red >> 3) + ((green >> 3) << 5) + ((blue >> 3) << 10);
}

static void m4_plot(int x, int y, u8 clrid)
{
    u16 *dst = &vid_page[(y * 240 + x) >> 1];
    if (x & 1)
    {
        *dst = (*dst & 0xFF) | (clrid << 8);
    }
    else
    {
        *dst = (*dst & ~0xFF) | clrid;
    }
}

COLOR *vid_flip()
{
    vid_page = (COLOR*)((u32)vid_page ^ VRAM_PAGE_SIZE);
    REG_DISPCNT ^= DCNT_PAGE;

    return vid_page;
}

void clear_screen()
{
    u16 fill = 0x0101;
    u16 *dst = (u16*)vid_page;
    int count = (240*160);
    for(int i = 0; i< count; i++)
    {
        dst[i] = fill;
    }
}

int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;

    ((u16 *)MEM_PAL)[1] = RGB8(55, 55, 55);
    ((u16 *)MEM_PAL)[2] = RGB8(255, 255, 255);

    int xpos = 1;
    int frame = 0;

    while (1)
    {
        vid_vsync();
        frame++;
        if(frame == 60)
        {
            frame = 0;
            xpos++;
            clear_screen();
            m4_plot(xpos, 10, 2);
            vid_flip();
        }
    }

    return 0;
}