#include "ktypes.h"
#include "video_primitive.h"
#include "kmemory.h"
#include "ports.h"

#define TEXTBUFFER_ADDR 0xB8000
_uint16 VidbufWidth = 80;
_uint16 VidbufHeight = 25;
const _uint16* VIDBUF = TEXTBUFFER_ADDR;

cursor_t screenCursor = {TEXTBUFFER_ADDR, 0, 0, 0x07};

void kvpScrollScreen(_uint16 lines)
{
  kmemcpy(VIDBUF + VidbufWidth, VIDBUF + VidbufWidth + VidbufWidth*lines,
    sizeof(unsigned short) * (VidbufWidth*(VidbufHeight-2)));
  kmemset(VIDBUF + VidbufWidth * (VidbufHeight-1), 0, VidbufHeight);
}

void kvpClearScreen(_uint8 attr)
{
  kmemset(VIDBUF, 0, VidbufHeight * VidbufWidth * sizeof(_uint16));
  screenCursor.x = 0;
  screenCursor.y = 0;
  screenCursor.attr = 0x4F;
  kputs("   NebulaOS                                                            kern_out ");
  screenCursor.attr = 0x07;  
  screenCursor.x = 0;
  screenCursor.y = 1;
  kvpUpdateCursor();
}

void kvpUpdateCursor()
{
  _uint8 hwcursl;
  _uint8 hwcursh;
  
  if (screenCursor.x >= VidbufWidth)
  {
    screenCursor.y += screenCursor.x / VidbufWidth;
    screenCursor.x = screenCursor.x % VidbufWidth;
  }
  if (screenCursor.y >= VidbufHeight)
  {
    kvpScrollScreen(1 + screenCursor.y - VidbufHeight);
    screenCursor.y = VidbufHeight - 1;
  }

  screenCursor.ptr = VIDBUF + screenCursor.y * VidbufWidth + screenCursor.x;
  
  // Update hardware cursor position
  hwcursl = (_uint8)((screenCursor.ptr - VIDBUF) & (0x00FF));
  hwcursh = (_uint8)(((screenCursor.ptr - VIDBUF) & (0xFF00)) >> 8);
  outp(0x03D4, 0x0F);
  outp(0x03D5, hwcursl);
  outp(0x03D4, 0x0E);
  outp(0x03D5, hwcursh);
}

// Process a character for any single-character escapes and return the result.
_uint8 kvpProcessEscape(_uint8 c)
{
  switch (c)
  {
    case '\n':
      screenCursor.y++;
      break;
    case '\r':
      screenCursor.x = 0;
      break;
    default:
      return c;
  }
  return 0;
}

void kvpPutChar(_uint8 c)
{
  if (kvpProcessEscape(c))
  {
    *(screenCursor.ptr) = (_uint16) c | (_uint16) (screenCursor.attr) << 8;
    screenCursor.x++;
  }
  kvpUpdateCursor();
}

cursor_t kvpCloneScreenCursor()
{
  cursor_t clone = screenCursor;
  return clone;
}

void kvpSetScreenCursor(cursor_t curs)
{
  screenCursor = curs;
}
