bits 32

section .text
global _start

_start:
  mov eax, 0x04
  add eax, 0x01
  mov ebx, eax

  jmp 0x0
