#ifndef VIDEO_H
#define VIDEO_H

#include "memory_map.h"
#include "types.h"

#include "named_type.h"

#include <cstdint>

using dcnt_video_mode_t = named_type<std::uint32_t, struct dcnt_video_mode_tag>;
using dcnt_background_t = named_type<std::uint32_t, struct dcnt_background_tag>;

// --- REG_DISPCNT defines ---
constexpr auto const DCNT_MODE0 = dcnt_video_mode_t{0x0000};
constexpr auto const DCNT_MODE1 = dcnt_video_mode_t{0x0001};
constexpr auto const DCNT_MODE2 = dcnt_video_mode_t{0x0002};
constexpr auto const DCNT_MODE3 = dcnt_video_mode_t{0x0003};
constexpr auto const DCNT_MODE4 = dcnt_video_mode_t{0x0004};
constexpr auto const DCNT_MODE5 = dcnt_video_mode_t{0x0005};

constexpr auto const DCNT_PAGE = unsigned{0x0010};

// layers
constexpr auto const DCNT_BG0 = dcnt_background_t{0x0100};
constexpr auto const DCNT_BG1 = dcnt_background_t{0x0200};
constexpr auto const DCNT_BG2 = dcnt_background_t{0x0400};
constexpr auto const DCNT_BG3 = dcnt_background_t{0x0800};
constexpr auto const DCNT_OBJ = dcnt_background_t{0x1000};

#define MODE3_SCREEN_WIDTH 240
#define MODE3_SCREEN_HEIGHT 160

#define MODE4_SCREEN_WIDTH 240
#define MODE4_SCREEN_HEIGHT 160

#define MODE5_SCREEN_WIDTH 160
#define MODE5_SCREEN_HEIGHT 128

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
	using memory::vram;
	reinterpret_cast<vram::pointer>(vram::base)[y * MODE3_SCREEN_WIDTH + x] = clr;
}


void video_vsync(void);

class idisplay_ctl
{
public:
	virtual void set(dcnt_video_mode_t video_mode, dcnt_background_t background_mode) = 0;
};

class display_control : public idisplay_ctl
{
public:
	void set(dcnt_video_mode_t video_mode, dcnt_background_t background_mode) override
	{
		using memory::set;
		using memory::REG_DISPCNT;

		set<REG_DISPCNT>(video_mode | background_mode);
	}
};

struct display
{
	display(idisplay_ctl& disp_ctl) : disp_ctl{disp_ctl} {}

	void set_display_control(dcnt_video_mode_t vmode, dcnt_background_t bgmode)
	{
		disp_ctl.set(vmode, bgmode);
	}

	idisplay_ctl& disp_ctl;
};


#endif
