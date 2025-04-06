#ifndef MAIN_H
#define MAIN_H

typedef unsigned char u8;

typedef unsigned short u16;
typedef volatile u16 vu16;
typedef u16 COLOR;

typedef unsigned int u32;

typedef volatile u32 vu32;

#define INLINE static inline

#define MEM_IO		0x04000000
#define MEM_PAL		0x05000000
#define MEM_VRAM	0x06000000

#define M4_SIZE			0x09600
#define VRAM_PAGE_SIZE  0x0A000

#define MEM_VRAM_BACK   (MEM_VRAM + VRAM_PAGE_SIZE)

#define vid_mem         ((COLOR*)MEM_VRAM)
#define vid_mem_front   ((COLOR*)MEM_VRAM)
#define vid_mem_back    ((COLOR*)MEM_VRAM_BACK)

#define REG_BASE        MEM_IO

#define REG_DISPCNT     *(vu32*)(REG_BASE+0x0000)
#define REG_VCOUNT		*(vu16*)(REG_BASE+0x0006)	// vertical count

#define DCNT_MODE4		0x0004	//!< Mode 4; bg2: 240x160\@8 bitmap
#define DCNT_PAGE       0x0010
#define DCNT_BG2		0x0400	//!< Enable bg 2

#define SCREEN_WIDTH	240
#define SCREEN_HEIGHT	160
#define M4_WIDTH	SCREEN_WIDTH
#define M4_HEIGHT	SCREEN_HEIGHT

INLINE void vid_vsync();
u16 *vid_flip();

INLINE void vid_vsync()
{
	while(REG_VCOUNT >= 160);	// wait till VDraw
	while(REG_VCOUNT < 160);	// wait till VBlank
}

#endif