#include "kstdio.h"
#include "video_primitive.h"

void k_main(void* MB_INFO, unsigned int MB_MAGIC)
{
  kvpClearScreen();
  for (char i = 0; i < 30; i++)
  {
    kputs("Hello, world! ");
    kputb(i);
    kputs("\r\n");
  }
  return;
}
