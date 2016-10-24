#pragma once

#include <utility>

#include <cstdint>

constexpr auto const MEM_IO   = unsigned{0x04000000};
constexpr auto const MEM_VRAM = unsigned{0x06000000};

constexpr auto const VRAM_PAGE_SIZE = unsigned{0x0A000};

constexpr auto const REG_DISPCNT = uint32_t{0x0000};
constexpr auto const REG_VCOUNT  = uint16_t{0x0006};

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
	constexpr auto set(typename T::value_type const value)
	    -> typename std::enable_if<is_region<T>::value,
	                               void>::type
	{
		*reinterpret_cast<typename T::pointer>(T::address) = value;
	}

	template <typename T>
	constexpr auto get()
	    -> volatile typename T::value_type const&
	{
		return *reinterpret_cast<typename T::pointer>(T::address);
	}
};
