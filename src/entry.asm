[BITS 32]

global loader
extern k_main

MB_MODULEALIGN  equ     1<<0
MB_MEMINFO      equ     1<<1
MB_FLAGS        equ     MB_MODULEALIGN | MB_MEMINFO
MB_MAGIC        equ     0x1BADB002
MB_CHECKSUM     equ     -(MB_MAGIC + MB_FLAGS)

section .text

align 4
    dd MB_MAGIC
    dd MB_FLAGS
    dd MB_CHECKSUM

STACKSIZE   equ     0x4000 ; 16K

loader:
    mov esp, stack + STACKSIZE  ; Set stack pointer
    push eax                    ; Push MB magic number onto the stack
    push ebx                    ; Push MB information structure onto the stack

    call k_main ; Call the kernel entry point

    cli ; Disable interupts
.hang:
    hlt
    jmp .hang

section .bss

align 4
stack:
    resb STACKSIZE
