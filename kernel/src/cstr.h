#include <stdint.h>
#ifndef CSTR
#define CSTR

char *int_to_string(int64_t value);

char *float_to_string(float value, int round);

char *hex_to_string(uint64_t value, uint64_t size);
#endif