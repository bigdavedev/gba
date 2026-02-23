add_library (ptb_gba_base INTERFACE)
add_library (PtB::Gba::Base ALIAS ptb_gba_base)

target_sources (
    ptb_gba_base

    INTERFACE
    FILE_SET ptb_gba_headers
    TYPE HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
    FILES
    ptb/gba/base.hpp
)