#include "bios.h"
#include "cpu.h"
#include <bits/stdint-uintn.h>
#include <bits/types/FILE.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <errno.h>

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
  sector = cpu.registers[1].read_8l() & 0x3f;
  cylinder = (uint16_t)((cpu.registers[1].read_8l() & 0xc0) >> 6) << 8| cpu.registers[1].read_8h(); 
  buf_addr = cpu.es * 16 + cpu.registers[3].read_16();
  head = cpu.registers[2].read_8h();

  printf("sector: %d, cylinder: %d, head: %d\n", sector, cylinder, head);

  long offset = (80 * 18 * 512) * head + 512 * sector + cylinder * (512 * 18);

  FILE *fp;
  fp = fopen(file_name.c_str(), "rb");
  if (fseek(fp, offset, SEEK_SET) != 0) {
    fprintf(stderr, "[e] fseek\n");
    exit(1);
  }

  unsigned char buf[512];
  
  errno = 0;
  fread(buf, sizeof(char), sizeof(buf), fp);
  if (errno != 0) {
    perror("fread");
    exit(1);
  }

  cpu.memory.write(buf_addr, buf, sizeof(buf));

  printf("write %dbyte at 0x%x\n", 512, buf_addr);
}
