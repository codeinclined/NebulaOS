/******************************************************************************
 *      k_main.c
 ******************************************************************************
 *  Entry point of C code for the COG kernel.
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
