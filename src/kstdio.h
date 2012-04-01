#ifndef K_STDIO_H
#define K_STDIO_H

#include "kernel.h"

void kputs(const char* str);
void kputb(const char byte);
void kputba(const char* bytes, size_t len);

#endif
