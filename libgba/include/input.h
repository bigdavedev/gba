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

class ikey_input
{
public:
    virtual void poll() = 0;

    virtual bool key_down(key val) const = 0;

    virtual bool key_was_down(key val) const = 0;

    virtual bool key_up(key val) const = 0;

    virtual bool key_was_up(key val) const = 0;
};

class key_input final : public ikey_input
{
public:
	void poll() override;

	bool key_down(key val) const override;

	bool key_was_down(key val) const override;

	bool key_up(key val) const override;

	bool key_was_up(key val) const override;

private:
	memory::REG_KEYINPUT::value_type state;
	memory::REG_KEYINPUT::value_type previous_state;
};

}
#endif
