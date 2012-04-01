#include "kernel.h"

void* kmemcpy(void* dest, const void *src, size_t n)
{
  volatile unsigned char* dst8 = (unsigned char*)dest;
  volatile unsigned char* src8 = (unsigned char*)src;

  while (n--)
    *dst8++ = *src8++;

  return dest;
}

void* kmemset(void *ptr, char ch, size_t n)
{
  volatile unsigned char* p = (unsigned char*)ptr;
  while (n--)
    *p++ = ch;
  return ptr;
}
