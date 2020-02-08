bits 32

section .text
global _start

_start:
  mov eax, 0x04
  add eax, 0x01
  mov ebx, eax

  mov eax, 1
  mov ebx, ebx
  int 0x80
