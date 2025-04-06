#include "draw.h"

#define MAX_COLORS 256

RGB colors[MAX_COLORS] =
    {
        {0, 0, 0},       // BLACK
        {125, 125, 125}, // GRAY
        {255, 255, 255}, // WHITE
        {255, 0, 0},     // RED
        {0, 255, 0},     // GREEN
        {0, 0, 255},     // BLUE
};

int num_colors = 6;

COLOR RGB8(RGB value)
{
    return (value.r >> 3) + ((value.g >> 3) << 5) + ((value.b >> 3) << 10);
}

void setup_vid_base_pal()
{
    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++)
    {
        ((u16 *)MEM_PAL)[i] = RGB8(colors[i]);
    }
}

void add_vid_pal(u8 r, u8 g, u8 b)
{
    if (num_colors < MAX_COLORS)
    {
        RGB clr = {r, g, b};
        colors[num_colors++] = clr;
        ((u16 *)MEM_PAL)[num_colors - 1] = RGB8(clr);
    }
}

void plot(int x, int y, u8 clrid)
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