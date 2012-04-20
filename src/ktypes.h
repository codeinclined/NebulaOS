/******************************************************************************
 *       ktypes.h
 ******************************************************************************
 *  Header file defining variable types for different target platforms
 *  the kernel may be compiled for.
 ******************************************************************************
 *  TODO:
 *  ...
 ******************************************************************************
 *  Authors: Joshua Taylor <>
 *  Project: NebulaOS
 *  Module:  COG
 *  Created: 2012-04-20
 *  License: zlib License
 ******************************************************************************
 *  Copyright (c) 2012 Joshua Taylor <>
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

#ifndef __K_TYPES_H
#define __K_TYPES_H

#include "kernel.h"

#ifdef __NEBULAOS_x86_32     // 32-bit x86 protected mode

typedef unsigned char        _uint8;
typedef char                  _int8;
typedef unsigned char        _ubyte;
typedef char                  _byte;

typedef unsigned short       _uint16;
typedef short                 _int16;
typedef unsigned short       _uword;
typedef short                 _word;

typedef unsigned int         _uint32;
typedef int                   _int32;
typedef unsigned int         _udword;
typedef int                   _dword;

typedef unsigned long long  _uint64;
typedef long long            _int64;
typedef unsigned long long  _uqword;
typedef long long            _qword;

#endif // 32-bit x86 protected mode

#endif // __K_TYPES_H

