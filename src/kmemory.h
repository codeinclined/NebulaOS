#ifndef K_MEMORY_H
#define K_MEMORY_H

#include "kernel.h"

void* kmemcpy(void* dest, const void *src, size_t n);
void* kmemset(void *ptr, char ch, size_t n);

#endif
