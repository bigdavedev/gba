#include "video.h"

void video_vsync()
{
	while (memory::get<memory::REG_VCOUNT>() >= 160)
		; // wait till VDraw
	while (memory::get<memory::REG_VCOUNT>() < 160)
		; // wait till VBlank
}
