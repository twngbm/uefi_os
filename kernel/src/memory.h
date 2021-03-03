#include <stdint.h>
#include <stddef.h>
#include "kernel_struct.h"
#ifndef MEMORY
#define MEMORY

extern uint64_t GetMemorySize(EFI_MEMORY_DESCRIPTOR *mMap, uint64_t mMapEntries, uint64_t mMapDescSize);
#endif