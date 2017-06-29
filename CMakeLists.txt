cmake_minimum_required (VERSION 3.2)

set (CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/toolchain.gba.cmake)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project (rom)

set (TARGET_NAME ${PROJECT_NAME})

add_executable (${TARGET_NAME} "")

target_compile_options (
	${TARGET_NAME}
	PUBLIC
	-std=c++1z
	-Wall
	-Wextra
	-Wpedantic
	-Werror
)

target_sources (${TARGET_NAME}
	PRIVATE
	source/video.cpp
	source/main.cpp
)

target_include_directories (${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(${PROJECT_NAME}
                      PROPERTIES
                      LINK_FLAGS ${CMAKE_GBA_LINKER_FLAGS}
)

include (gba)

convert_to_gba (${TARGET_NAME})
