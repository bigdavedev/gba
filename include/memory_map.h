#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include "types.h"

#define MEM_IO 0x04000000
#define MEM_VRAM 0x06000000

#define VRAM_PAGE_SIZE 0x0A000

#define MEM_VRAM_BACK (MEM_VRAM + VRAM_PAGE_SIZE)

#define REG_DISPCNT *((volatile uint32_t*)(MEM_IO + 0x0000))
#define REG_VCOUNT *((volatile uint16_t*)(MEM_IO + 0x0006))

#endif
