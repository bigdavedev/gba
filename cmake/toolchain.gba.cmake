message (STATUS "devkitpro root directory: ${DEVKITPRO_ROOT}")

set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_SYSTEM_PROCESSOR arm-none-eabi)

find_program(CMAKE_MAKE_PROGRAM make)

set (CMAKE_FIND_ROOT_PATH ${DEVKITPRO_ROOT})

set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

find_program (CMAKE_C_COMPILER ${DEVKITPRO_ROOT}/bin/${CMAKE_SYSTEM_PROCESSOR}-gcc)
find_program (CMAKE_CXX_COMPILER ${DEVKITPRO_ROOT}/bin/${CMAKE_SYSTEM_PROCESSOR}-g++)
find_program (CMAKE_LINKER ${DEVKITPRO_ROOT}/bin/${CMAKE_SYSTEM_PROCESSOR}-ld)
find_program (CMAKE_AR ${DEVKITPRO_ROOT}/bin/${CMAKE_SYSTEM_PROCESSOR}/ar)
find_program (CMAKE_OBJCOPY ${DEVKITPRO_ROOT}/bin/${CMAKE_SYSTEM_PROCESSOR}-objcopy)
find_program (CMAKE_STRIP ${DEVKITPRO_ROOT}/bin/${CMAKE_SYSTEM_PROCESSOR}-strip)

message(STATUS "Looking for gbafix...")
find_program (GBAFIX gbafix ${DEVKITPRO_ROOT}/bin)
if(GBAFIX)
	message(STATUS "Looking for gbafix: ${GBAFIX} - found")
else(GBAFIX)
	message(FATAL_ERROR "Looking for gbafix: ${GBAFIX} - not found")
endif(GBAFIX)

set (ARCH "-mthumb-interwork -mthumb")
set (SPECS -specs=gba.specs)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${ARCH} -fno-strict-aliasing")
set (CMAKE_GBA_LINKER_FLAGS "${ARCH} ${SPECS} -Wl,-Map=rom.map")
