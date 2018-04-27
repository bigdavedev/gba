#include "video.h"

void video_vsync()
{
	while (memory::get<memory::REG_VCOUNT>() >= 160)
		; // wait till VDraw
	while (memory::get<memory::REG_VCOUNT>() < 160)
		; // wait till VBlank
}

void display_control::set(dcnt_video_mode video_mode, dcnt_background_mode background_mode)
{
using memory::set;
using memory::REG_DISPCNT;

set<REG_DISPCNT>(video_mode | background_mode);
}

void display::set_display_control(dcnt_video_mode vmode, dcnt_background_mode bgmode)
{
	disp_ctl.set(vmode, bgmode);
}