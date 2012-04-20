/******************************************************************************
 *       kstdio.c
 ******************************************************************************
 *  Basic input / output functions for kernel code. This is not meant to
 *  be an implementation of the C standard stdio code.
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
#include "kernel.h"
#include "video_primitive.h"

void kputs(const _uint8* str)
{
  const _uint8* c = str;
  while (*c != 0)
  {
    kvpPutChar(*c);
    c++;
  }
}

// Hacky way to print a byte in hex format
void kputb(const _uint8 byte)
{
  _uint8 buf[3];
  buf[0] = 0x30 + ((byte & 0xF0) >> 4);
  if (buf[0] >= 0x3A)
    buf[0] = 0x41 + (buf[0] - 0x3A);
  buf[1] = 0x30 + (byte & 0x0F);
  if (buf[1] >= 0x3A)
    buf[1] = 0x41 + (buf[1] - 0x3A);
  buf[2] = '\0';
  kputs(buf);
}

void kputba(const _uint8* bytes, size_t len)
{
  for (_uint8* by = bytes+len-1; by >= bytes; by--)
    kputb(*by);
}
