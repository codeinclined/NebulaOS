#ifndef K_MEMORY_H
#define K_MEMORY_H

#include "ktypes.h"
#include "kernel.h"

void* kmemcpy(void* dest, const void *src, size_t n);
void* kmemset(void *ptr, _uint8 ch, size_t n);
void* kmemsetv(void* ptr, void* chs, size_t width, size_t n);

#endif
