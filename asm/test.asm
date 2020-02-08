bits 32

section .text
global _start

_start:
  mov ebx, 0x01
  add ebx, 0x01

  mov eax, 1
  int 0x80
