#include "video.h"

#include "memory_def.h"
#include "memory_map.h"

void video_vsync()
{
	while (memory::get<memory::REG_VCOUNT>() >= 160)
		; // wait till VDraw
	while (memory::get<memory::REG_VCOUNT>() < 160)
		; // wait till VBlank
}
