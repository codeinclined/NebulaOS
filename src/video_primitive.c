#include "video_primitive.h"
#include "kmemory.h"

#define TEXTBUFFER_ADDR 0xB8000
unsigned int VidbufWidth = 80;
unsigned int VidbufHeight = 25;
const unsigned short* VIDBUF = TEXTBUFFER_ADDR;

cursor_t screenCursor = {TEXTBUFFER_ADDR, 0, 0, 0x07};

void kvpScrollScreen(unsigned int lines)
{
  kmemcpy(VIDBUF, VIDBUF+VidbufWidth*lines,
    sizeof(unsigned short) * (VidbufWidth*(VidbufHeight-1)));
  kmemset(VIDBUF + VidbufWidth * (VidbufHeight-1), 0, VidbufHeight);

}

void kvpClearScreen()
{
  kmemset(VIDBUF, 0, VidbufHeight * VidbufWidth * sizeof(unsigned short));
  screenCursor.x = 0;
  screenCursor.y = 0;
}

void kvpUpdateCursor()
{
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
}

// Process a character for any single-character escapes and return the result.
unsigned char kvpProcessEscape(unsigned char c)
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

void kvpPutChar(unsigned char c)
{
  kvpUpdateCursor();
  if (kvpProcessEscape(c))
  {
    *(screenCursor.ptr) = (unsigned short)c |
                          (unsigned short)(screenCursor.attr) << 8;
    screenCursor.x++;
  }
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
