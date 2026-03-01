# Copyright 2026 David Brown <d.brown@bigdavedev.com>
# SPDX short identifier: MIT
add_library (ptb_gba_base)
add_library (PtB::Gba::Base ALIAS ptb_gba_base)

target_sources (
    ptb_gba_base

    PUBLIC
    FILE_SET ptb_gba_base_modules
    TYPE CXX_MODULES
    FILES
    types.ixx
    base.ixx
)