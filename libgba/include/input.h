#ifndef INPUT_H
#define INPUT_H

#include <memory_map.h>

#include <type_traits>

namespace input
{

enum class key : memory::REG_KEYINPUT::value_type
{
	A      = 0x0001,
	B      = 0x0002,
	SELECT = 0x0004,
	START  = 0x0008,
	RIGHT  = 0x0010,
	LEFT   = 0x0020,
	UP     = 0x0040,
	DOWN   = 0x0080,
	L      = 0x0100,
	R      = 0x0200
};

class key_input
{
public:
	inline void poll()
	{
		using memory::get;
		using memory::REG_KEYINPUT;

		constexpr static auto mask = REG_KEYINPUT::value_type{ 0x03FF };

		state = ~get<REG_KEYINPUT>() & mask;
	}

	inline bool key_down(key val)
	{
		return state & static_cast<std::underlying_type_t<key>>(val);
	}

	inline bool key_up(key val)
	{
		return ~state & static_cast<std::underlying_type_t<key>>(val);
	}
private:
	memory::REG_KEYINPUT::value_type state;
};

}
#endif
