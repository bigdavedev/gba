#include "types.h"
#include "video.h"

void draw_line_16bpp(int startx,
					 int starty,
					 int endx,
					 int endy,
					 uint32_t colour,
					 void* canvas_base,
					 unsigned int pitch);

void draw_rectangle_16bpp(int left,
						  int top,
						  int right,
						  int bottom,
						  uint32_t colour,
						  void* canvas_base,
						  unsigned int pitch);

void draw_frame_16bpp(int left,
					  int top,
					  int right,
					  int bottom,
					  uint32_t colour,
					  void *canvas_base,
					  unsigned int pitch);

static inline void mode3_draw_line(int startx, int starty, int endx, int endy, uint32_t colour)
{
	draw_line_16bpp(startx, starty, endx, endy, colour, vid_mem, MODE3_SCREEN_WIDTH*2);
}

static inline void mode3_draw_rectangle(int left, int top, int right, int bottom, uint32_t colour)
{
    draw_rectangle_16bpp(left, top, right, bottom, colour, vid_mem, MODE3_SCREEN_WIDTH*2);
}

static inline void mode3_draw_frame(int left, int top, int right, int bottom, uint32_t colour)
{
	draw_frame_16bpp(left, top, right, bottom, colour, vid_mem, MODE3_SCREEN_WIDTH*2);
}
