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

