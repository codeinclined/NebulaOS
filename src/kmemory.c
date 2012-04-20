/******************************************************************************
 *       kmemory.c
 ******************************************************************************
 *  Code for managing memory at a low level for kernel code.
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
#include "kstdio.h"

void* kmemcpy(void* dest, const void *src, size_t n)
{
  volatile _uint8* dst8 = (_uint8*)dest;
  volatile _uint8* src8 = (_uint8*)src;

  while (n--)
    *dst8++ = *src8++;

  return dest;
}

void* kmemset(void *ptr, _uint8 ch, size_t n)
{
  volatile _uint8* p = (_uint8*)ptr;
  while (n--)
    *p++ = ch;
  return ptr;
}

void* kmemsetv(void* ptr, void* chs, size_t width, size_t n)
{
  volatile _uint8* p = (_uint8*)ptr;
  
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < width; j++)
      *p++ = *( ((_uint8*)(chs)) + j);
  
  return ptr;
}

