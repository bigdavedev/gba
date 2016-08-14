#include "geometry.h"

void draw_line_16bpp(int startx,
					 int starty,
					 int endx,
					 int endy,
					 uint32_t colour,
					 void* canvas_base,
					 unsigned int pitch)
{
	uint16_t* canvas = (uint16_t*)(canvas_base + starty * pitch + startx * 2);
	pitch = pitch >> 1;

	int dx = 0;
	int xstep = 0;
	if (startx > endx)
	{
		xstep = -1;
		dx = startx - endx;
	}
	else
	{
		xstep = 1;
		dx = endx - startx;
	}

	int dy = 0;
	int ystep = 0;
	if (starty > endy)
	{
		ystep = -pitch;
		dy = starty - endy;
	}
	else
	{
		ystep = +pitch;
		dy = endy - starty;
	}

	if (dy == 0) /* horizontal line */
	{
		for (int i = 0; i <= dx; ++i)
		{
			canvas[i*xstep] = colour;
		}
	}
	else if (dx == 0) /* vertical line */
	{
		for (int i = 0; i <= dy; ++i)
		{
			canvas[i*ystep] = colour;
		}
	}
	else if(dx>=dy)     // Diagonal, slope <= 1
	{
		int dd = 2*dy - dx;

		for(int i=0; i<=dx; ++i)
		{
			*canvas= colour;
			if(dd >= 0)
			{   dd -= 2*dx; canvas += ystep;  }

			dd += 2*dy;
			canvas += xstep;
		}               
	}
	else                // Diagonal, slope > 1
	{
		int dd= 2*dx - dy;
		for(int i=0; i<=dy; ++i)
		{
			*canvas = colour;
			if(dd >= 0)
			{   dd -= 2*dy; canvas += xstep;  }

			dd += 2*dx;
			canvas += ystep;
		}    
	}
}

void draw_rectangle_16bpp(int left,
						  int top,
						  int right,
						  int bottom,
						  uint32_t colour,
						  void *canvas_base,
						  unsigned int pitch)
{
    int width = right-left, height = bottom-top;
    uint16_t *canvas = (uint16_t*)(canvas_base+top*pitch + left*2);
    pitch = pitch >> 1;

    // --- Draw ---
    for(int iy=0; iy<height; iy++)
		for(int ix=0; ix<width; ix++)
			canvas[iy*pitch + ix]= colour;
}

void draw_frame_16bpp(int left,
					  int top,
					  int right,
					  int bottom,
					  uint32_t colour,
					  void *canvas_base,
					  unsigned int pitch)
{
	// Frame is RB exclusive
	right--;
	bottom--;

	draw_line_16bpp(left,  top,   right,  top,    colour, canvas_base, pitch);
	draw_line_16bpp(left,  bottom, right, bottom, colour, canvas_base, pitch);

	draw_line_16bpp(left,  top,   left,   bottom, colour, canvas_base, pitch);
	draw_line_16bpp(right, top,   right,  bottom, colour, canvas_base, pitch);
}
