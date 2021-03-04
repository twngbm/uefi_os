#include <stdint.h>
#include <stddef.h>
#include "kernel_static.h"
#include "kernel_struct.h"
#ifndef MEMORY
#define MEMORY

typedef struct {
   uint64_t memoryMap;
} MMAP;

extern uint64_t getMSize(EFI_MEMORY_DESCRIPTOR *mMap, uint64_t mMapEntries, uint64_t mMapDescSize);

extern uint8_t isMFree(uint32_t addr);

extern void initM();

extern uint32_t malloc(uint32_t size);

extern void free(uint32_t addr);


#endif
