#include "main.h"

char position[32];

typedef struct {
    int x;
    int y;
    int z;
}vertex;

typedef struct {
    vertex vert[3];
}triangle;


int main()
{
    REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
    setup_vid_base_pal();

    change_bg_clr(WHITE);

    triangle tri;
    tri.vert[0] = (vertex){10, 10, 0};
    tri.vert[1] = (vertex){30, 10, 0};
    tri.vert[2] = (vertex){10, 30, 0};

    while (1)
    {
        // --- WAIT FOR NEW UPDATE ---
        vid_vsync();

        // --- REMOVE OLD INFO ---
        clear_screen();
        scan_keys();
        
        // --- UPDATE INFO ---
       

        // --- DRAW NEW INFO ---        
        
        for (int v = 0; v < 3; v++)
        {
            plot(tri.vert[v].x, tri.vert[v].y, RED);
        }

        // --- SHOW NEW INFO ---
        vid_flip();
    }

    return 0;
}