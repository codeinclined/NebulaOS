#include "kernel.h"
#include "video_primitive.h"

void kputs(const char* str)
{
  const char* c = str;
  while (*c != 0)
  {
    kvpPutChar(*c);
    c++;
  }
}

// Hacky way to print a byte in hex format
void kputb(const char byte)
{
  char buf[3];
  buf[0] = 0x30 + ((byte & 0xF0) >> 4);
  if (buf[0] >= 0x3A)
    buf[0] = 0x41 + (buf[0] - 0x3A);
  buf[1] = 0x30 + (byte & 0x0F);
  if (buf[1] >= 0x3A)
    buf[1] = 0x41 + (buf[1] - 0x3A);
  buf[2] = '\0';
  kputs(buf);
}

void kputba(const char* bytes, size_t len)
{
  for (char* by = bytes+len-1; by >= bytes; by--)
    kputb(*by);
}
