# Copyright 2026 David Brown <d.brown@bigdavedev.com>
# SPDX short identifier: MIT
add_subdirectory (base)

add_library (ptb_gba)
add_library (PtB::Gba ALIAS ptb_gba)

target_sources (
    ptb_gba

    PUBLIC
    FILE_SET ptb_gba_modules
    TYPE CXX_MODULES
    FILES
    gba.ixx
)

target_link_libraries (
    ptb_gba

    PUBLIC
    PtB::Gba::Base
)