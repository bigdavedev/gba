cmake_minimum_required (VERSION 3.2)

set (CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/toolchain.gba.cmake)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project (frogger C)

set (TARGET_NAME ${PROJECT_NAME})

set (SOURCES source/frogger.c
             source/geometry.c
             source/video.c)

add_executable (${TARGET_NAME} ${SOURCES})
target_include_directories (${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME} PROPERTIES
	  LINK_FLAGS ${CMAKE_GBA_LINKER_FLAGS})

include (gba)

convert_to_gba (${TARGET_NAME})
