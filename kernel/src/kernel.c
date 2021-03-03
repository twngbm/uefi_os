#include <output.h>
#include <cstr.h>
#include <memory.h>
Framebuffer *framebuffer;
PSF1_FONT *psf1_font;
unsigned int cours_x;
unsigned int cours_y;

void Kprint(unsigned int colour, char *str, int newline)
{
    char *chr = str;
    while (*chr != 0)
    {
        putChar(colour, *chr, cours_x, cours_y, framebuffer, psf1_font);
        (cours_x) += 8;
        chr++;
    }
    if (newline)
    {
        (cours_y) += 16;
        (cours_x) = 0;
    }
}

void _start(BootInfo *bootInfo)
{
    framebuffer = bootInfo->framebuffer;
    psf1_font = bootInfo->psf1_Font;
    cours_x = 0;
    cours_y = 0;
    uint64_t MemorySize = 0;
    cls(framebuffer);
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

    for (int i = 0; i < mMapEntries; i++)
    {
        EFI_MEMORY_DESCRIPTOR *desc = (EFI_MEMORY_DESCRIPTOR *)((uint64_t)bootInfo->mMap + (i * bootInfo->mMapDescSize));
        Kprint(0xffffffff, int_to_string(i + 1), 0);
        Kprint(0xffffffff, " ", 0);
        Kprint(0xffffffff, EFI_MEMORY_TYPE_STRINGS[desc->Type], 0);
        Kprint(0xffffffff, " ", 0);
        Kprint(0xffff00ff, int_to_string(desc->numPages * 4), 0);
        Kprint(0xffff00ff, " KB ", 1);
        //MemorySize += desc->numPages * 4;
    }
    MemorySize = GetMemorySize(bootInfo->mMap, mMapEntries, bootInfo->mMapDescSize);
    Kprint(0xffff00ff, int_to_string(MemorySize), 0);
    Kprint(0xffff00ff, " KB in Total", 1);
    while (1)
    {
        __asm__("hlt");
    }
    return;
}