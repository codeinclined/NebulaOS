[BITS 32]

global loader
extern k_main
extern kputs

MB_MODULEALIGN  equ     1<<0
MB_MEMINFO      equ     1<<1
MB_GRAPHINFO    equ     1<<2
MB_FLAGS        equ     MB_MODULEALIGN | MB_MEMINFO | MB_GRAPHINFO
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
