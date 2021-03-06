#include "memory.h"
#include "kernel_struct.h"
#include <stdint.h>
uint64_t getMSize(EFI_MEMORY_DESCRIPTOR *mMap, uint64_t mMapEntries, uint64_t mMapDescSize)
{
    static uint64_t memorySizeBytes = 0;
    if (memorySizeBytes > 0)
    {
        return memorySizeBytes;
    }
    for (int i = 0; i < mMapEntries; i++)
    {
        EFI_MEMORY_DESCRIPTOR *desc = (EFI_MEMORY_DESCRIPTOR *)((uint64_t)mMap + (i * mMapDescSize));
        memorySizeBytes += desc->numPages * 4;
    }
    return memorySizeBytes;
}


