#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdbool.h>

typedef unsigned char u8;

typedef unsigned short u16;
typedef volatile u16 vu16;
typedef u16 COLOR;

typedef unsigned int u32;

typedef volatile u32 vu32;

typedef signed int s32;

#define INLINE static inline

typedef struct {
    u8 r;
    u8 g;
    u8 b;
}RGB;

#endif 