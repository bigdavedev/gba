project (gba)

set (TARGET_NAME ${PROJECT_NAME})

add_library (${TARGET_NAME} INTERFACE)

target_compile_options (
	${TARGET_NAME}

	INTERFACE
	-std=c++1z
	-Wall
	-Wextra
	-Wpedantic
	-Werror
	-fno-exceptions
        -fvisibility=hidden
        -fwhole-program
)

target_sources (
	${TARGET_NAME}
        INTERFACE
	${PROJECT_SOURCE_DIR}/source/video.cpp
        ${PROJECT_SOURCE_DIR}/source/input.cpp
)

target_include_directories (
	${TARGET_NAME}
    INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


