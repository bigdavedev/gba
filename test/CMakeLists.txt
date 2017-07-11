cmake_minimum_required (VERSION 3.5)

project (test_rom CXX)

set (TARGET ${PROJECT_NAME})

add_executable (${TARGET} "")

target_compile_options (
	${TARGET}

	PUBLIC
	-std=c++1z
)

target_sources (
	${TARGET}

	PUBLIC
	${PROJECT_SOURCE_DIR}/test_display.cpp

	PRIVATE
	${CMAKE_SOURCE_DIR}/source/video.cpp
	${PROJECT_SOURCE_DIR}/main.cpp
)

target_include_directories (
	${TARGET}

	SYSTEM PUBLIC
	gtest
	gmock

	PUBLIC
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries (
	${TARGET}

	PUBLIC
	gtest
	gmock
)

add_test (${TARGET} ${CMAKE_RUNTIME_OUTPUT_DIR}/${TARGET})
