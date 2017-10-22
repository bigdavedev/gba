#pragma once

#include <utility>

#include <cstdint>

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
