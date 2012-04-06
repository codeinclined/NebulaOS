#include "ktypes.h"
#include "kernel.h"
#include "kstdio.h"

void* kmemcpy(void* dest, const void *src, size_t n)
{
  volatile _uint8* dst8 = (_uint8*)dest;
  volatile _uint8* src8 = (_uint8*)src;

  while (n--)
    *dst8++ = *src8++;

  return dest;
}

void* kmemset(void *ptr, _uint8 ch, size_t n)
{
  volatile _uint8* p = (_uint8*)ptr;
  while (n--)
    *p++ = ch;
  return ptr;
}

void* kmemsetv(void* ptr, void* chs, size_t width, size_t n)
{
  volatile _uint8* p = (_uint8*)ptr;
  
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < width; j++)
      *p++ = *( ((_uint8*)(chs)) + j);
  
  return ptr;
}

