#ifndef VIDEO_H
#define VIDEO_H

#include "memory_map.h"
#include "types.h"

#define MODE3_SCREEN_WIDTH 240
#define MODE3_SCREEN_HEIGHT 160

#define MODE4_SCREEN_WIDTH 240
#define MODE4_SCREEN_HEIGHT 160

#define MODE5_SCREEN_WIDTH 160
#define MODE5_SCREEN_HEIGHT 128

#define vid_mem ((uint16_t*)MEM_VRAM)

#define CLR_BLACK 0x0000
#define CLR_RED 0x001F
#define CLR_LIME 0x03E0
#define CLR_YELLOW 0x03FF
#define CLR_BLUE 0x7C00
#define CLR_MAG 0x7C1F
#define CLR_CYAN 0x7FE0
#define CLR_WHITE 0x7FFF

static inline colour RGB15(uint32_t red, uint32_t green, uint32_t blue)
{
	return red | (green << 5) | (blue << 10);
}

inline void mode3_plot(int x, int y, colour clr)
{
	vid_mem[y * MODE3_SCREEN_WIDTH + x] = clr;
}

void video_vsync(void);
void vid_flip(void);

#endif
