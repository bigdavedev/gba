#pragma once

#include "memory.h"
#include "named_type.h"

using vram_address_t = named_type<std::uint16_t, struct vram_address_tag>;
using mem_address_t = named_type<std::uint16_t, struct mem_address_tag>;

namespace memory
{
	using io   = region<uint32_t{0x04000000}, uint32_t>;
	using vram = region<uint32_t{0x06000000}, uint16_t>;

	struct REG_DISPCNT : io
	{
		constexpr static auto const address = base + uint32_t{0x0000};
	};

	struct REG_KEYINPUT : io
	{
		constexpr static auto const address = base + uint32_t{0x0130};
	};

	struct REG_VCOUNT : io
	{
		constexpr static auto const address = base + uint32_t{0x0006};
	};

	struct MEM_VRAM_BACK : vram
	{
		constexpr static auto const address = base + uint32_t{0x0A000};
	};
}
