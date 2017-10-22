#ifndef VIDEO_H
#define VIDEO_H

#include "memory_map.h"
#include "types.h"

#include "named_type.h"

#include <type_traits>

#include <cstdint>

// --- REG_DISPCNT defines ---
enum class dcnt_video_mode : memory::REG_DISPCNT::value_type
{
	MODE0 = 0x0000,
	MODE1 = 0x0001,
	MODE2 = 0x0002,
	MODE3 = 0x0003,
	MODE4 = 0x0004,
	MODE5 = 0x0005
};

constexpr auto const DCNT_PAGE = unsigned{0x0010};

// layers
enum class dcnt_background_mode : memory::REG_DISPCNT::value_type
{
	BG0 = 0x0100,
	BG1 = 0x0200,
	BG2 = 0x0400,
	BG3 = 0x0800,
	OBJ = 0x1000
};

inline auto operator|(dcnt_video_mode vmode, dcnt_background_mode bgmode)
	-> memory::REG_DISPCNT::value_type
{
	return static_cast<std::underlying_type_t<dcnt_video_mode>>(vmode) |
	       static_cast<std::underlying_type_t<dcnt_background_mode>>(bgmode);
}

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
	virtual void set(dcnt_video_mode video_mode, dcnt_background_mode background_mode) = 0;
};

class display_control : public idisplay_ctl
{
public:
	void set(dcnt_video_mode video_mode, dcnt_background_mode background_mode) override
	{
		using memory::set;
		using memory::REG_DISPCNT;

		set<REG_DISPCNT>(video_mode | background_mode);
	}
};

class display
{
public:
	display(idisplay_ctl& disp_ctl) : disp_ctl{disp_ctl} {}

	void set_display_control(dcnt_video_mode vmode, dcnt_background_mode bgmode)
	{
		disp_ctl.set(vmode, bgmode);
	}

	idisplay_ctl& disp_ctl;
};


#endif
