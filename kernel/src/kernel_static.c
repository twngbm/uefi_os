#include "kernel_struct.h"
#include "kernel_static.h"
Framebuffer *framebuffer = 0x00;
PSF1_FONT *psf1_font = 0x00;
uint32_t cours_x = 0;
uint32_t cours_y = 0;
uint32_t memSize = 0;

char *EFI_MEMORY_TYPE_STRINGS[] = {
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
