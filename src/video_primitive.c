/******************************************************************************
 *       video_primitive.c
 ******************************************************************************
 *  Very primitive video functions for use in the early stages of the kernel.
 *  The functions provided in this file should mainly be used by kernel
 *  library code, such as kstdio.c, and not used directly very often.
 ******************************************************************************
 *  TODO:
 *  ...
 ******************************************************************************
 *  Authors: Joshua Taylor <taylor.joshua88@gmail.com>
 *  Project: NebulaOS
 *  Module:  COG
 *  Created: 2012-04-20
 *  License: zlib License
 ******************************************************************************
 *  Copyright (c) 2012 Joshua Taylor <taylor.joshua88@gmail.com>
 *
 *    This software is provided 'as-is', without any express or implied
 *    warranty. In no event will the authors be held liable for any damages
 *    arising from the use of this software.
 *
 *    Permission is granted to anyone to use this software for any purpose,
 *    including commercial applications, and to alter it and redistribute it
 *    freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 *    2. Altered source versions must be plainly marked as such, and must not
 *    be misrepresented as being the original software.
 *
 *    3. This notice may not be removed or altered from any source
 *    distribution.
 *****************************************************************************/

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
