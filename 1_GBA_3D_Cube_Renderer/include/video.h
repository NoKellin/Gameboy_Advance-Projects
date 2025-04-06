#ifndef VIDEO_H
#define VIDEO_H

#include "types.h"
#include "memory.h"

#define MEM_VRAM	0x06000000

#define SCREEN_WIDTH	240
#define SCREEN_HEIGHT	160
#define M4_WIDTH	SCREEN_WIDTH
#define M4_HEIGHT	SCREEN_HEIGHT

#define VRAM_PAGE_SIZE  0x0A000

#define MEM_VRAM_BACK   (MEM_VRAM + VRAM_PAGE_SIZE)

#define vid_mem         ((COLOR*)MEM_VRAM)
#define vid_mem_front   ((COLOR*)MEM_VRAM)
#define vid_mem_back    ((COLOR*)MEM_VRAM_BACK)

#define REG_DISPCNT     *(vu32*)(REG_BASE+0x0000)
#define REG_VCOUNT		*(vu16*)(REG_BASE+0x0006)	// vertical count

#define DCNT_MODE4		0x0004	//!< Mode 4; bg2: 240x160\@8 bitmap
#define DCNT_PAGE       0x0010
#define DCNT_BG2		0x0400	//!< Enable bg 2

extern COLOR *vid_page;

void vid_vsync();
void clear_screen();
COLOR *vid_flip();

#endif