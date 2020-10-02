run:
	cd build && make
	cd asm && make test.img
	./x86emu asm/test.img
