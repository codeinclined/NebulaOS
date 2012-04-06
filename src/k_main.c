#include "ktypes.h"
#include "kstdio.h"
#include "video_primitive.h"
#include "kmemory.h"

extern cursor_t screenCursor;

void k_main(void* MB_INFO, _uint32 MB_MAGIC)
{ 
//  kmemsetv((_uint32*)0xB8000, (_uint16*) 0xFF0A, 2, 5);
    kputba(0, 1);
    kputs("\r\n");
    kputba(1, 1);
    kputs("\r\n");

    kputba(2, 1);
    kputs("\r\n");

    kputba(3, 1);
    kputs("\r\n");
    //kvpScrollScreen(1);
/*  
  kputs("\r\nScanning multiboot information...");

  if (MB_MAGIC != 0x2BADB002)
  {
    screenCursor.attr = 0x04;
    kputs("Multiboot information missing! Kernel halting..");
    kputs("\r\n-->           0x");
    kputba(&MB_MAGIC, sizeof(_uint32));
    kputs("\r\n--> Expected: 0x2BADB002");
    return;
  }
  else
  {
    screenCursor.attr = 0x02;
    kputs("done");
    kputs("\r\n-->  0x");
    kputba(&MB_MAGIC, sizeof(_uint32));
  }
*/
  return;
}
