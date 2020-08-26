#include "bios.h"
#include "cpu.h"
#include <bits/stdint-uintn.h>
#include <bits/types/FILE.h>
#include <cstdio>

void software_interrupt(CPU &cpu)
{
  uint8_t vector = cpu.get_code8();
  cpu.eip++;

  int ret;

  switch (vector) {
    case 0x13:
      printf("int 0x13: disk service\n");
      ret = disk_service(cpu);

      if (ret == 0) {
        cpu.eflags &= 0x7fffffff;
      } else {
        cpu.eflags |= 0x80000000;
      }
      break;
    default:
      printf("int 0x%02x: can not implement\n", vector);
      break;
  }
}

int disk_service(CPU &cpu)
{
  uint8_t ah = cpu.registers[0].read_8h();

  printf("bios interruption: disk_service, func=%d\n", ah);

  switch (ah) {
    case 0x02:
      printf("bios interruption: read sector\n");
      read_disk(cpu);
      break;
    default:
      printf("can not implement, func=0x%02x\n", ah);
      break;
  }

  return 0;
}

void read_disk(CPU &cpu)
{
  uint8_t al, sector, head;
  uint16_t cylinder;
  uint32_t buf_addr;

  std::string file_name = cpu.manager.disk_name;

  al = cpu.registers[0].read_8l();
  sector = cpu.registers[1].read_8l() & 0x31;
  cylinder = (cpu.registers[1].read_8l() & 0xc0) | cpu.registers[1].read_8h(); 
  buf_addr = cpu.es * 16 + cpu.registers[3].read_16();
  head = cpu.registers[2].read_8h();

  long offset;

  FILE *fp;
  fp = fopen(file_name.c_str(), "rb");
  fseek(fp, offset, SEEK_SET);

  unsigned char buf[512];
  fread(buf, sizeof(char), sizeof(buf), fp);

  cpu.memory.write(buf_addr, buf, sizeof(buf));
}
