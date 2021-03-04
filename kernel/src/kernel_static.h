#include <stdint.h>
#include "kernel_struct.h"
#ifndef KERNEL_STATIC
#define KERNEL_STATIC
typedef uint8_t bool;
extern Framebuffer *framebuffer;
extern PSF1_FONT *psf1_font;
extern uint32_t cours_x;
extern uint32_t cours_y;
extern uint32_t memSize;
extern char *EFI_MEMORY_TYPE_STRINGS[];
#endif
