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
  char buf[5];
  buf[0] = '0';
  buf[1] = 'x';
  buf[2] = 0x30 + (byte >> 4);
  if (buf[2] >= 0x3A)
    buf[2] = 0x41 + (buf[2] - 0x3A);
  buf[3] = 0x30 + (byte & 0x0F);
  if (buf[3] >= 0x3A)
    buf[3] = 0x41 + (buf[3] - 0x3A);
  buf[4] = '\0';
  kputs(buf);
}
