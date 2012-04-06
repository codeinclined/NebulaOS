#ifndef K_VIDEO_PRIMITIVE_H
#define K_VIDEO_PRIMITIVE_H

#include "ktypes.h"

typedef struct {
  _uint16* ptr;
  _uint16 x;
  _uint16 y;
  _uint8 attr;
} cursor_t;

void kvpPutChar(_uint8 c);
void kvpScrollScreen(_uint16 lines);
unsigned char kvpProcessEscape(_uint8 c);
void kvpClearScreen(_uint8 attrib);
cursor_t kvpCloneScreenCursor();
void kvpSetScreenCursor(cursor_t curs);

#endif
