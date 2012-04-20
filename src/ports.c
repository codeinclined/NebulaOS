/******************************************************************************
 *       ports.c
 ******************************************************************************
 *  Code to complement ports.asm (basic port I/O)
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

#include "kmemory.h"
#include "ktypes.h"

/*
void outp(_uint16 port, _uint8 data)
{
  asm volatile 
  (
    "outb %0, %1"
    :
    :  "r" (data), "r" (port)
    :  "memory"
  );
}

void outpw(_uint16 port, _uint16 data)
{
  asm volatile 
  (
    "outw %0, %1"
    :
    :  "r" (data), "r" (port)
    :  "memory"
  );
}

void outpdw(_uint16 port, _uint32 data)
{
  asm volatile 
  (
    "outl %0, %1"
    :
    :  "r" (data), "r" (port)
    :  "memory"
  );
}

_uint8 inp(_uint16 port)
{
  _uint8 ret;
  
  asm volatile
  (
    "inb %0, %1"
    :  "=r" (ret)
    :  "r" (port)
    : "memory"
  );
  
  return ret;
}

_uint16 inpw(_uint16 port)
{
  _uint16 ret;
  
  asm volatile
  (
    "inw %1, %0"
    :  "=r" (ret)
    :  "r" (port)
    :  "memory"
  );
  
  return ret;
}

_uint32 inpdw(_uint16 port)
{
  _uint32 ret;
  
  asm volatile
  (
    "inl %1, %0"
    :  "=r" (ret)
    :  "r" (port)
    :  "memory"
  );
  
  return ret;
}
*/
