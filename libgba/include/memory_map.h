#pragma once

#include "memory.h"
#include "named_type.h"
#include "utility.h"

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

	template<uint32_t index>
	struct REG_BGCNT : io
	{
		static_assert(utility::in_range<index, 0, 3>::value,
		              "Index for BCNT not valid");
		constexpr static auto const address = base + uint32_t{0x0008} + (2*index);
	};

	using REG_BGCNT_0 = REG_BGCNT<4>;

	template<uint32_t index>
	struct REG_BGHOFS : io
	{
		constexpr static auto const address = base + uint32_t{0x0010} + (4*index);
	};

	template<uint32_t index>
	struct REG_BGVOFS : io
	{
		constexpr static auto const address = base + uint32_t{0x0012} + (4*index);
	};

	struct MEM_VRAM_BACK : vram
	{
		constexpr static auto const address = base + uint32_t{0x0A000};
	};
}
