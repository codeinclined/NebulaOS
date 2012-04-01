#include "kmemory.h"

/*
#define VIDBUFFER_WIDTH 80
#define VIDBUFFER_HEIGHT 25
#define VIDBUFFER_MAX 0xB8000 + (VIDBUFFER_HEIGHT * VIDBUFFER_WIDTH * 2)
#define VIDBUFFER_MIN 0xB8000

unsigned short* cursor = VIDBUFFER_MIN;
unsigned char cursorX = 0;
unsigned char cursorY = 0;
*/

/*


void kvpPutChar(unsigned char c, unsigned char fg, unsigned char bg)
{
  unsigned short attrib = (bg << 4) | (fg & 0x0F);
  if (kvpProcessEscape(c))
  {
    *cursor = c | (attrib << 8);
    kvpMoveCursor(cursorX+1, cursorY);
  }
}
*/

#define TEXTBUFFER_ADDR 0xB8000
unsigned int VidbufWidth = 80;
unsigned int VidbufHeight = 25;
const unsigned short* VIDBUF = TEXTBUFFER_ADDR;

struct {
  unsigned short* ptr;
  unsigned int x;
  unsigned int y;
  unsigned char attr;
} cursor = {TEXTBUFFER_ADDR, 0, 0, 0x07};

void kvpScrollScreen(unsigned int lines)
{
  kmemcpy(VIDBUF, VIDBUF+VidbufWidth*lines,
    sizeof(unsigned short) * (VidbufWidth*(VidbufHeight-1)));
  kmemset(VIDBUF + VidbufWidth * (VidbufHeight-1), 0, VidbufHeight);

}

void kvpClearScreen()
{
  kmemset(VIDBUF, 0, VidbufHeight * VidbufWidth * sizeof(unsigned short));
  cursor.x = 0;
  cursor.y = 0;
}

void kvpUpdateCursor()
{
  if (cursor.x >= VidbufWidth)
  {
    cursor.y += cursor.x / VidbufWidth;
    cursor.x = cursor.x % VidbufWidth;
  }
  if (cursor.y >= VidbufHeight)
  {
    kvpScrollScreen(1 + cursor.y - VidbufHeight);
    cursor.y = VidbufHeight - 1;
  }

  cursor.ptr = VIDBUF + cursor.y * VidbufWidth + cursor.x;
}

// Process a character for any single-character escapes and return the result.
unsigned char kvpProcessEscape(unsigned char c)
{
  switch (c)
  {
    case '\n':
      cursor.y++;
      break;
    case '\r':
      cursor.x = 0;
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
    *(cursor.ptr) = (unsigned short)c | (unsigned short)(cursor.attr) << 8;
    cursor.x++;
  }
}
