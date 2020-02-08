.PHONY: clean

bin: test.asm
	nasm -o test.bin test.asm

elf: test.asm
	nasm -f elf64 test.asm
	ld test.o

run: elf
	./a.out

clean:
	rm -f *.o *.bin a.out
