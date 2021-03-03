#include "output.h"
#include "cstr.h"
#include "kernel_static.h"
#include "kernel_struct.h"
#include "memory.h"

void _start(BootInfo *bootInfo)
{
    framebuffer = bootInfo->framebuffer;
    psf1_font = bootInfo->psf1_Font;
    cours_x = 0;
    cours_y = 0;
    uint64_t MemorySize = 0;
    cls();
    /*
    Kprint(0xffffffff, int_to_string(64), 1);
    Kprint(0xffffffff, int_to_string(-72), 1);
    Kprint(0xffffffff, float_to_string(64.7854, 2), 1);
    Kprint(0xffffffff, float_to_string(65.7854, 8), 1);
    Kprint(0xffffffff, float_to_string(-64.7854, 2), 1);
    Kprint(0xffffffff, float_to_string(-65.7854, 8), 1);
    Kprint(0xffffffff, hex_to_string(0xab, sizeof(a)), 1);
    Kprint(0xffffffff, hex_to_string(0xabcd, 2), 1);
    Kprint(0xffffffff, hex_to_string(0x12abcdef, 4), 1);
    Kprint(0xffffffff, hex_to_string(0x1234567890abcdef, 8), 1);
*/
    uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescSize;
    MemorySize = GetMemorySize(bootInfo->mMap, mMapEntries, bootInfo->mMapDescSize);
    Kprint(0xffff00ff, int_to_string(MemorySize), 0);
    Kprint(0xffff00ff, " KB in Total.", 1);
    for (int i = 0; i < mMapEntries; i++)
    {
        EFI_MEMORY_DESCRIPTOR *desc = (EFI_MEMORY_DESCRIPTOR *)((uint64_t)bootInfo->mMap + (i * bootInfo->mMapDescSize));
        Kprint(0xffffffff, int_to_string(i + 1), 0);
        Kprint(0xffffffff, " ", 0);
        Kprint(0xffffffff, EFI_MEMORY_TYPE_STRINGS[desc->Type], 0);
        Kprint(0xffffffff, " ", 0);
        Kprint(0xffff00ff, int_to_string(desc->numPages * 4), 0);
        Kprint(0xffff00ff, " KB", 1);
        //MemorySize += desc->numPages * 4;
    }

    while (1)
    {
        __asm__("hlt");
    }
    return;
}