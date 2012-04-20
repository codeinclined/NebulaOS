;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;       entry.asm
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Entry-point code for the kernel. This file assumes COG was loaded via
;  a multiboot compliant bootloader. The goal of this file is to do the bare
;  minimum required to set the kernel up to be coded in C.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  TODO:
;  ~ Write code to switch into long mode (Pri 1)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Author:  Joshua William Taylor <taylor.joshua88@gmail.com>
;  Project: NebulaOS
;  Created: 19APR2012
;  License: zlib License
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Copyright (c) 2012 Joshua William Taylor <taylor.joshua88@gmail.com>
;
;    This software is provided 'as-is', without any express or implied
;    warranty. In no event will the authors be held liable for any damages
;    arising from the use of this software.
;
;    Permission is granted to anyone to use this software for any purpose,
;    including commercial applications, and to alter it and redistribute it
;    freely, subject to the following restrictions:
;
;    1. The origin of this software must not be misrepresented; you must not
;    claim that you wrote the original software. If you use this software
;    in a product, an acknowledgment in the product documentation would be
;    appreciated but is not required.
;
;    2. Altered source versions must be plainly marked as such, and must not be
;    misrepresented as being the original software.
;
;    3. This notice may not be removed or altered from any source
;    distribution.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[BITS 32]

global loader
extern k_main
extern kputs

MB_MODULEALIGN  equ     1<<0
MB_MEMINFO      equ     1<<1
MB_FLAGS        equ     MB_MODULEALIGN | MB_MEMINFO
MB_MAGIC        equ     0x1BADB002
MB_CHECKSUM     equ     -(MB_MAGIC + MB_FLAGS)

STACK_SIZE      equ     0x5000 ; 16K

section .text

align 4
    dd MB_MAGIC
    dd MB_FLAGS
    dd MB_CHECKSUM

loader:
    mov esp, stack + STACK_SIZE  ; Set stack pointer
    push eax                    ; Push MB magic number onto the stack
    push ebx                    ; Push MB information structure onto the stack

    cli ; Disable interupts
    call k_main ; Call the kernel entry point
.hang:
    push dword hngstr
    call kputs
    hlt
    jmp .hang

section .data
    hngstr db 13,10,10,"!!~~ Reached end of kernel code. Halting CPU ~~!!",0

section .bss
align 32
stack:
    resb STACK_SIZE
