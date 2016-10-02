#include "video.h"

#include "memory_def.h"
#include "memory_map.h"

static uint32_t* vid_page = ((uint32_t*)MEM_VRAM_BACK);

void video_vsync()
{
	while (REG_VCOUNT >= 160)
		; // wait till VDraw
	while (REG_VCOUNT < 160)
		; // wait till VBlank
}

uint32_t* vid_flip(void)
{
	vid_page = (uint32_t*)((uint32_t)vid_page ^ VRAM_PAGE_SIZE);
	REG_DISPCNT ^= DCNT_PAGE;

	return vid_page;
}
