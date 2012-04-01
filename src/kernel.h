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
