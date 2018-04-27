project (rom)

add_executable (
	rom

	source/main.cpp
)

target_link_libraries (
	rom

	PUBLIC
	gba
)

include(CheckIPOSupported)
check_ipo_supported()

set_target_properties(
	rom
	PROPERTIES
	LINK_FLAGS
	${CMAKE_GBA_LINKER_FLAGS}
	INTERPROCEDURAL_OPTIMIZATION TRUE
)

include (gba)

convert_to_gba (rom)
