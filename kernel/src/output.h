#include "kernel_struct.h"
#ifndef OUTPUT
#define OUTPUT
extern Framebuffer *framebuffer;
extern PSF1_FONT *psf1_font;
extern uint32_t cours_x;
extern uint32_t cours_y;

void cls();

void putChar(unsigned int colour, char chr, const unsigned int xOff, const unsigned int yOff);

void Kprint(unsigned int colour, char *str, int newline);

#endif