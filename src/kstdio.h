#ifndef K_STDIO_H
#define K_STDIO_H

#include "ktypes.h"
#include "kernel.h"

void kputs(const _byte* str);
void kputb(const _byte byte);
void kputba(const _byte* bytes, size_t len);

#endif

