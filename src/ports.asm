[BITS 32]
section .text

global outp
outp:
  mov dx, [esp+4]
  mov al, [esp+6]
  out dx, al
  ret

global outpw
outpw:
  mov dx, [esp+4]
  mov ax, [esp+6]
  out dx, ax
  ret

global inp
inp:
  mov dx, [esp+4]
  xor eax, eax
  in al, dx
  ret

global inpw
inpw:
  mov dx, [esp+4]
  xor eax, eax
  in ax, dx
  ret

