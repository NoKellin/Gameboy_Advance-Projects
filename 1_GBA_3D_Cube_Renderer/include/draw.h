#ifndef DRAW_H
#define DRAW_H

#include "types.h"
#include "video.h"

#define BLACK   1
#define GRAY    2
#define WHITE   3
#define RED     4
#define GREEN   5
#define BLUE    6

extern RGB base_colors[];

COLOR RGB8(RGB value);

void setup_vid_base_pal();
void add_vid_pal(u8 r, u8 g, u8 b);
void change_bg_clr(int clrid);

void plot(int x, int y, u8 clrid);
void draw_line(int x1, int y1, int x2, int y2, u8 clrid);
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, u8 clrid);

#endif