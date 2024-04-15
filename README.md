# x86 Emulator

## Requirements

* make, cmake (build system)
* freeglut (for GUI)

## Build

```
  mkdir build
  cd    build
  cmake ..
  make 
```
there is a test code in 'asm/'.
you have to install the following requirements.
* nasm
* mtools
* libc6-dev-i386

you can make `test.img` by excuting `make test.img` in `asm/`.
then, run `./x86emu asm/test.img`
