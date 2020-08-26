#include "cpu.h"
#include "bios.h"
#include <bits/stdint-uintn.h>
#include <iostream> 
#include <sstream>
#include <vector>
#include <bitset>
#include <cstdio>

void set_protected_mode(CPU &cpu)
{
  cpu.mode = PROTECTED_MODE;
}

void set_manager(CPU &cpu)
{
  cpu.manager.disk_name = "ipl.bin";
}

void load_ipl(unsigned char *buf)
{
  FILE *fp;

  fp = fopen("ipl.bin", "rb");


  fread(buf, sizeof(uint8_t), 512, fp);

  fclose(fp);

}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cout << "few argument\n";
    exit(1);
  }

  printf("load ipl\n");
  unsigned char buf[512];
  load_ipl(buf);

  CPU cpu{buf, 512, 0x7c00};

  set_manager(cpu);


  printf("start emulator\n");
  cpu.run();
  cpu.show_segment_registers();
}
