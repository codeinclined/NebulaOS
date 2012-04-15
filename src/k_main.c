#include "ktypes.h"
#include "kstdio.h"
#include "video_primitive.h"
#include "kmemory.h"

extern cursor_t screenCursor;

void k_main(void* MB_INFO, _uint32 MB_MAGIC)
{ 
  kvpClearScreen(0x00);

  if (MB_MAGIC != 0x2BADB002)
  {
    screenCursor.attr = 0x04;
    kputs("Multiboot information missing! Kernel halting..");
    kputs("\r\n-->           0x");
    kputba(&MB_MAGIC, sizeof(_uint32));
    kputs("\r\n--> Expected: 0x2BADB002\r\n");
    return;
  }
  else
  {
    screenCursor.attr = 0x02;
    kputs("done");
    kputs("\r\n-->  0x");
    kputba(&MB_MAGIC, sizeof(_uint32));
    kputs("\r\n");
  }

  for (_byte i=0; i < 30; i++)
  {
    kputb(i);
    kputs("\r\n");
  }

  return;
}
