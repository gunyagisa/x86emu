org 0xc200 
bits 32

VRAM equ   0xa0000

; protected mode
  lgdt  [GDTR0]
  mov   eax, cr0
  and   eax, 0x00000001
  mov   cr0, eax
  jmp   next

; set segment
next:
  mov   ax, 8
  mov   ds, ax
  mov   es, ax
  mov   fs, ax
  mov   gs, ax
  mov   ss, ax

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


GDT0:
	TIMES 8 DB 0
	DW		0xffff, 0x0000, 0x9200, 0x00cf
	DW		0xffff, 0x0000, 0x9a28, 0x0047

	DW		0
GDTR0:
	DW		8*3-1
	DD		GDT0

	TIMES 16 DB 0

