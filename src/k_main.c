#include "kstdio.h"
#include "video_primitive.h"

extern cursor_t screenCursor;

void k_main(void* MB_INFO, unsigned int MB_MAGIC)
{
  kvpClearScreen();
  screenCursor.attr = 0x4F;
  kputs("    NebulaOS pre0.0                                                             ");
  screenCursor.attr = 0x07;
  kputs("\r\nScanning multiboot information...");

  if (MB_MAGIC != 0x2BADB002)
  {
    screenCursor.attr = 0x04;
    kputs("Multiboot information missing! Kernel halting..");
    kputs("\r\n-->  0x");
    kputba(&MB_MAGIC, sizeof(unsigned int));
    kputs("     Expected: 0x");
    kputba(0x1BADB002, 4);
    return;
  }
  else
  {
    screenCursor.attr = 0x02;
    kputs("done");
    kputs("\r\n-->  0x");
    kputba(&MB_MAGIC, sizeof(unsigned int));
  }

  return;
}
