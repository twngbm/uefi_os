#include "kernel_struct.h"
#include "kernel_static.h"
#ifndef OUTPUT
#define OUTPUT

extern void cls();

extern void putChar(unsigned int colour, char chr, const unsigned int xOff, const unsigned int yOff);

extern void Kprint(unsigned int colour, char *str, int newline);

#endif