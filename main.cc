#include "cpu.h"
#include <iostream> 
#include <vector>
#include <bitset>
#include <cstdio>

void set_protected_mode(CPU &cpu)
{
  cpu.mode = PROTECTED_MODE;
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cout << "few argument\n";
    exit(1);
  }

  FILE *fp;
  size_t len;
  fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    perror("[E] :fopen");
    exit(1);
  }
  unsigned char buf[125];
  len = fread(buf, 1, sizeof(buf), fp);
  fclose(fp);

  /*
  for (int i = 0;i < len;++i) {
    printf("%x ", buf[i]);
  }
  std::cout << std::endl;
  */

  CPU cpu{buf, 1024, 0x7c00};
  printf("start emulator\n");
  cpu.run();
  cpu.show_segment_registers();
}

