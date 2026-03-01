// Copyright 2026 David Brown <d.brown@bigdavedev.com>
// SPDX short identifier: MIT

export module ptb.gba.base:types;

export namespace ptb::gba
{
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;

using s8 = signed char;
using s16 = signed short;
using s32 = signed int;

static_assert(sizeof(u8) == 1);
static_assert(sizeof(u16) == 2);
static_assert(sizeof(u32) == 4);

static_assert(sizeof(s8) == 1);
static_assert(sizeof(s16) == 2);
static_assert(sizeof(s32) == 4);
} // namespace ptb::gba
