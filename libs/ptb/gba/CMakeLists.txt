add_subdirectory (base)

add_library (ptb_gba INTERFACE)
add_library (PtB::Gba ALIAS ptb_gba)

target_link_libraries (
    ptb_gba

    INTERFACE
    PtB::Gba::Base
)