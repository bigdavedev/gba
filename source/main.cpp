#include "video.h"

int main()
{
	display_control disp_ctl{};
	display disp{disp_ctl};
	disp.set_display_control(dcnt_video_mode::MODE3, dcnt_background_mode::BG2);

	mode3_plot(100, 50, CLR_WHITE);
	mode3_plot(100, 51, CLR_RED);

	while (1)
	{
		video_vsync();
	}

	return 0;
}
