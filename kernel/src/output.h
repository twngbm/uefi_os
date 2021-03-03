#include <kernel.h>
void cls(Framebuffer *framebuffer)
{
    for (unsigned int x = 0; x < framebuffer->Width * 4; x += 4)
    {
        for (unsigned int y = 0; y < framebuffer->Height; y++)
        {
            *(unsigned int *)(x + (y * framebuffer->PixelsPerScanline * 4) + framebuffer->BaseAddress) = 0xff000000;
        }
    }
}

void putChar(unsigned int colour, char chr, const unsigned int xOff, const unsigned int yOff, Framebuffer *framebuffer, PSF1_FONT *psf1_font)
{
    unsigned int *pixPtr = (unsigned int *)framebuffer->BaseAddress;
    char *fontPtr = psf1_font->gliphBuffer + (chr * psf1_font->psf1_Header->charsize);
    for (unsigned long y = yOff; y < yOff + 16; y++)
    {
        for (unsigned long x = xOff; x < xOff + 8; x++)
        {
            if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0)
            {
                *(unsigned int *)(pixPtr + x + (y * framebuffer->PixelsPerScanline)) = colour;
            }
        }
        fontPtr++;
    }
}
