org 0xc200
bits 32

VRAM equ   0xa0000

boot_main:
  mov   ebx, VRAM
  mov   ecx, 16

loop:
  mov   eax, ebx
  div   ecx
  mov   al, dl
  mov   byte [ebx], al
  add   ebx, 1
  cmp   ebx, 0xaffff
  jbe   loop

fin:
  hlt
  jmp   fin
