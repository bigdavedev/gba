set (DEVKITPRO_ROOT $ENV{DEVKITPRO_ROOT})

if (DEVKITPRO_ROOT STREQUAL "")
	message (FATAL "You need to set DEVKITPRO_ROOT to point to you devkitpro installation")
endif()

set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_SYSTEM_PROCESSOR arm-none-eabi)

set (CMAKE_FIND_ROOT_PATH ${DEVKITPRO_ROOT})

find_program (CMAKE_OBJCOPY arm-none-eabi-objcopy)
find_program (CMAKE_LINKER arm-none-eabi-ld)
find_program (CMAKE_C_COMPILER arm-none-eabi-gcc)
find_program (CMAKE_CXX_COMPILER arm-none-eabi-g++)

set (ARCH "-mthumb-interwork -mthumb")
set (SPECS -specs=gba.specs)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${ARCH} -fno-strict-aliasing")
set (CMAKE_GBA_LINKER_FLAGS "${ARCH} ${SPECS}")

set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

