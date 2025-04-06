#ifndef DRAW_H
#define DRAW_H

#include "types.h"
#include "video.h"

#define BLACK   0
#define GRAY    1
#define WHITE   2
#define RED     3
#define GREEN   4
#define BLUE    5

extern RGB base_colors[];

COLOR RGB8(RGB value);

void setup_vid_base_pal();
void add_vid_pal(u8 r, u8 g, u8 b);

void plot(int x, int y, u8 clrid);


#endif