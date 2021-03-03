#include <stdint.h>
#ifndef KERNEL_STRUCT
#define KERNEL_STRUCT
typedef unsigned long long size_t;
typedef struct
{
    uint32_t Type;
    void *physAddr;
    void *virtAddr;
    uint64_t numPages;
    uint64_t attribs;
} EFI_MEMORY_DESCRIPTOR;

char EFI_MEMORY_TYPE_STRINGS[][40] = {
    "EfiReservedMemoryType",
    "EfiLoaderCode",
    "EfiLoaderData",
    "EfiBootServicesCode",
    "EfiBootServicesData",
    "EfiRuntimeServicesCode",
    "EfiRuntimeServicesData",
    "EfiConventionalMemory",
    "EfiUnusableMemory",
    "EfiACPIReclaimMemory",
    "EfiACPIMemoryNVS",
    "EfiMemoryMappedIO",
    "EfiMemoryMappedIOPortSpace",
    "EfiPalCode",
};

typedef struct
{
    void *BaseAddress;
    size_t BufferSize;
    unsigned int Width;
    unsigned int Height;
    unsigned int PixelsPerScanline;
} Framebuffer;

typedef struct
{
    unsigned char magic[2];
    unsigned char mode;
    unsigned char charsize;
} PSF1_HEADER;

typedef struct
{
    PSF1_HEADER *psf1_Header;
    void *gliphBuffer;
} PSF1_FONT;
typedef struct
{
    Framebuffer *framebuffer;
    PSF1_FONT *psf1_Font;
    EFI_MEMORY_DESCRIPTOR *mMap;
    uint64_t mMapSize;
    uint64_t mMapDescSize;
} BootInfo;
#endif