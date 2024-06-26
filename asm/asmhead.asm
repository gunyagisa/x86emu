org 0xc200 


; protected mode
  lgdt  [GDTR0]
  mov   eax, cr0
  or    ax, 0x0001
  mov   cr0, eax
  jmp   next

next:

bits 32

VRAM equ   0xa0000
BOOTPACK equ 0x00280000


; set segment
next:
  mov   ax, 8
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
  mov   eax, edx
  mov   [ebx], al
  add   ebx, 1
  cmp   ebx, 0xaffff
  jbe   loop

  mov   esi, bootpack
  mov   edi, BOOTPACK
  mov   eax, 1024 / 4
  call  memcpy


  mov   ebx, BOOTPACK
  mov   ecx, [ebx+16]
  add   ecx, 3
  mov   eax, ecx
  mov   ecx, 4
  div   ecx
  mov   ecx, eax
  jz    skip

  mov   esi, [ebx+20]
  add   edi, ebx
  mov   edi, [ebx+12]
  call  memcpy

  jmp   fin

skip:
  mov   esp, [ebx+12]
  jmp   2*8:0x0000001b


fin:
  hlt
  jmp   fin

memcpy:
  mov   ebx, [esi]
  add   esi, 4
  mov   [edi], ebx
  add   edi, 4
  sub   eax, 1
  jnz   memcpy
  ret

GDT0:
	TIMES 8 DB 0
	DW		0xffff, 0x0000, 0x9200, 0x00cf
	DW		0xffff, 0x0000, 0x9a28, 0x0047

	DW		0
GDTR0:
	DW		8*3
	DD		GDT0

	TIMES 16 DB 0

bootpack:
