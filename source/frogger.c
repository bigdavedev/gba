#include "geometry.h"
#include "memory_def.h"

int main()
{
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

	mode3_draw_rectangle( 12,  8, 108,  72, CLR_RED);
	mode3_draw_rectangle(108, 72, 132,  88, CLR_LIME);
	mode3_draw_rectangle(132, 88, 228, 152, CLR_BLUE);
	
	mode3_draw_frame(132,  8, 228,  72, CLR_CYAN);
    mode3_draw_frame(109, 73, 131,  87, CLR_BLACK);
    mode3_draw_frame( 12, 88, 108, 152, CLR_YELLOW);
	for (int i=0; i<=8; i++)
	{
		int j= 3*i+7;
		mode3_draw_line(132+11*i, 9, 226, 12+7*i, RGB15(j, 0, j));
		mode3_draw_line(226-11*i,70, 133, 69-7*i, RGB15(j, 0, j));
	}

	// Lines in bottom left frame
	for(int i=0; i<=8; i++)
	{
		int j= 3*i+7;
		mode3_draw_line(15+11*i, 88, 104-11*i, 150, RGB15(0, j, j));
	}
    
	while(1)
	{
        video_vsync();
    }

    return 0;
}
