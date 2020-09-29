.PHONY: clean

asmhead.bin: asmhead.asm
	nasm $< -o $@

ipl.bin: ipl.asm
	nasm $< -o $@

test.sys: asmhead.bin
	cat asmhead.bin > test.sys

test.img: test.sys ipl.bin
	mformat -f 1440 -C -B ./ipl.bin -i test.img ::
	mcopy test.sys -i test.img ::
