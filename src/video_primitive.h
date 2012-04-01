#ifndef K_VIDEO_PRIMITIVE_H
#define K_VIDEO_PRIMITIVE_H

typedef struct {
  unsigned short* ptr;
  unsigned int x;
  unsigned int y;
  unsigned char attr;
} cursor_t;

void kvpPutChar(unsigned char c);
void kvpScrollScreen(unsigned int lines);
unsigned char kvpProcessEscape(unsigned char c);
void kvpClearScreen();
cursor_t kvpCloneScreenCursor();
void kvpSetScreenCursor(cursor_t curs);

#endif
