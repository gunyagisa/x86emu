bits 32

section .text

global io_hlt, io_in8, io_out8


io_hlt:
  hlt
  jmp   io_hlt

io_in8: ; uint8 io_in8(uint16 port);
  mov   dx, [esp + 4]
  in   al, dx
  ret

io_out8: ; void io_out8(uint16 port, uint8 data);
  mov   dx, [esp + 4]
  mov   al, [esp + 8]
  out   dx, al
  ret
