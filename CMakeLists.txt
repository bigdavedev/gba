cmake_minimum_required (VERSION 3.9)

add_subdirectory (libgba)

if (NOT TESTING)
	set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

	add_subdirectory (rom)

else()
	enable_testing ()
	set (BUILD_GTEST OFF CACHE BOOL "" FORCE)
	set (BUILD_GMOCK ON CACHE BOOL "" FORCE)
	add_subdirectory (${CMAKE_SOURCE_DIR}/external/googletest)
	add_subdirectory (test)
endif()
