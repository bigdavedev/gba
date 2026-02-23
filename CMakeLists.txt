# Copyright 2026 David Brown <d.brown@bigdavedev.com>
# SPDX short identifier: MIT
cmake_minimum_required (VERSION 3.31)

project (
    gba
    VERSION 0.1.0
    DESCRIPTION "A Game Boy Advance game written in C++"
    LANGUAGES CXX
)

add_subdirectory (libs)

add_executable (gba)

target_sources (
    gba
    
    PRIVATE
    src/main.cpp
)

target_link_libraries (
    gba

    PRIVATE
    PtB::Gba
)

gba_create_rom (gba)