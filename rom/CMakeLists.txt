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

set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
	LINK_FLAGS
	${CMAKE_GBA_LINKER_FLAGS}
	INTERPROCEDURAL_OPTIMIZATION TRUE
)

include (gba)

convert_to_gba (rom)
