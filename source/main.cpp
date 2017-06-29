#include "video.h"

int main()
{
	set_display_control(DCNT_MODE3, DCNT_BG2);

	mode3_plot(140, 50, CLR_RED);

	while (1)
	{
		video_vsync();
	}

	return 0;
}
