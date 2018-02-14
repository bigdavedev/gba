#include "video.h"
#include "input.h"

int main()
{
	display_control disp_ctl{};
	display disp{disp_ctl};
	disp.set_display_control(dcnt_video_mode::MODE3, dcnt_background_mode::BG2);

	input::key_input keys{};

	mode3_plot(100, 50, CLR_WHITE);

	while (1)
	{
		video_vsync();

		keys.poll();

		if (keys.key_down(input::key::A))
		{
			mode3_plot(100, 60, CLR_WHITE);
		}
		else
		{
			mode3_plot(100, 60, CLR_RED);
		}
	}

	return 0;
}
