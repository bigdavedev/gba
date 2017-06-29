#pragma once

#include "named_type.h"

#include <utility>

#include <cstdint>

using vram_address_t = named_type<std::uint16_t, struct vram_address_tag>;
using mem_address_t = named_type<std::uint16_t, struct mem_address_tag>;

namespace memory
{
	template <uint32_t BaseAddress,
	          typename ValueType,
	          typename PointerType>
	struct region;

	template <typename T,
	          bool result = std::is_base_of<region<T::base,
	                                               typename T::value_type,
	                                               typename T::pointer>,
	                                        T>::value>
	struct is_region : std::false_type
	{
	};

	template <typename T>
	struct is_region<T, true> : std::true_type
	{
	};

	template <uint32_t BaseAddress,
	          typename ValueType,
	          typename PointerType = ValueType*>
	struct region
	{
		constexpr static auto const base = BaseAddress;
		using value_type                 = ValueType;
		using pointer                    = PointerType;
	};

	using io   = region<uint32_t{0x04000000}, uint32_t>;
	using vram = region<uint32_t{0x06000000}, uint16_t>;

	struct REG_DISPCNT : io
	{
		constexpr static auto const address = base + uint32_t{0x0000};
	};

	struct REG_VCOUNT : io
	{
		constexpr static auto const address = base + uint32_t{0x0006};
	};

	struct MEM_VRAM_BACK : vram
	{
		constexpr static auto const address = base + uint32_t{0x0A000};
	};

	template <typename T>
	constexpr void set(typename T::value_type const value)
	{
		static_assert(is_region<T>::value, "Not a memory region");
		*reinterpret_cast<typename T::pointer>(T::address) = value;
	}

	template <typename T>
	constexpr auto get()
	    -> volatile typename T::value_type&
	{
		static_assert(is_region<T>::value, "Not a memory region");
		return *reinterpret_cast<typename T::pointer>(T::address);
	}
}
