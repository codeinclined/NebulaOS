/******************************************************************************
 *       kernel.h
 ******************************************************************************
 *  Basic header file for sources dealing with kernel code.
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

#ifndef K_KERNEL_H
#define K_KERNEL_H

// Which version of the kernel are we using?
#define __NEBULAOS_x86_32     // 32-bit x86 protected mode
//#define __NEBULAOS_x86_64   // 64-bit x86_64 long mode

// 32-bit kernel
#ifdef __NEBULAOS_x86_32
typedef unsigned long size_t;
#endif // __NEBULAOS_x86_32

// 64-bit kernel constants
#ifdef __NEBULAOS_x86_64
typedef unsigned long long size_t;
#endif // __NEBULAOS_x86_64

#endif // K_KERNEL_H
