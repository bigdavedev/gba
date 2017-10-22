#pragma once

template<typename T, typename Tag>
struct named_type
{
	constexpr explicit named_type(T value)
		: value{value}
	{}

	constexpr named_type& operator=(T value)
	{
		this->value = value;
		return *this;
	}

	constexpr operator T() const
	{
		return value;
	}

private:
	T value;
};
