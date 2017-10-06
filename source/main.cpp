#include "video.h"

int main()
{
	display_control disp_ctl{};
	display disp{disp_ctl};
	disp.set_display_control(DCNT_MODE3, DCNT_BG2);

	mode3_plot(100, 50, CLR_WHITE);
	mode3_plot(100, 51, CLR_RED);

	while (1)
	{
		video_vsync();
	}

	return 0;
}
