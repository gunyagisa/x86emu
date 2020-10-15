.PHONY: clean

CC = clang
LD = ld.lld

asmhead.bin: asmhead.asm
	nasm $< -o $@

ipl.bin: ipl.asm
	nasm $< -o $@
asm_func.bin: asm_func.s
	nasm $< -o $@ -f elf32

boot.bin: boot_main.c asm_func.bin
	$(CC) $< -c -m32 -fno-stack-protector -fno-pic --target=i386
	$(LD) boot_main.o asm_func.bin -e main -melf_i386 -T ./har.ld -o $@

test.sys: asmhead.bin boot.bin
	cat asmhead.bin boot.bin > test.sys

test.img: test.sys ipl.bin
	mformat -f 1440 -C -B ./ipl.bin -i test.img ::
	mcopy test.sys -i test.img ::

clean:
	rm *.bin *.o *.sys *.img
