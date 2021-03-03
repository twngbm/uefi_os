#include <stdint.h>
#ifndef CSTR
#define CSTR

extern char *int_to_string(int64_t value);

extern char *float_to_string(float value, int round);

extern char *hex_to_string(uint64_t value, uint64_t size);
#endif