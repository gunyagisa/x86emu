org 0x7c00
bits 32


jmp 0x2c00

loop:
  hlt
  jmp   loop
