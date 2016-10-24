#pragma once

// --- REG_DISPCNT defines ---
constexpr auto const DCNT_MODE0 = unsigned{0x0000};
constexpr auto const DCNT_MODE1 = unsigned{0x0001};
constexpr auto const DCNT_MODE2 = unsigned{0x0002};
constexpr auto const DCNT_MODE3 = unsigned{0x0003};
constexpr auto const DCNT_MODE4 = unsigned{0x0004};
constexpr auto const DCNT_MODE5 = unsigned{0x0005};

constexpr auto const DCNT_PAGE = unsigned{0x0010};

// layers
constexpr auto const DCNT_BG0 = unsigned{0x0100};
constexpr auto const DCNT_BG1 = unsigned{0x0200};
constexpr auto const DCNT_BG2 = unsigned{0x0400};
constexpr auto const DCNT_BG3 = unsigned{0x0800};
constexpr auto const DCNT_OBJ = unsigned{0x1000};

