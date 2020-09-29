org 0xc200
bits 32

VRAM equ   0xa0000

boot_main:
  mov   esi, 0
  mov   ebx, VRAM

loop:
  mov   edx, 0x07
  call  write8
  add   esi, 1
  add   ebx, 1
  cmp   esi, 0xffff
  jbe    loop

fin:
  hlt
  jmp   fin

write8:
  mov   [ebx], edx
  ret
