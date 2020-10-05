bits 32

section .text

global io_hlt


io_hlt:
  hlt
  jmp   io_hlt
