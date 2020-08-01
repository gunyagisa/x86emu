#include "bios.h"
#include <cstdio>

void software_interrupt(CPU &cpu)
{
  uint8_t vector = cpu.get_code8();
  cpu.eip++;

  int ret;

  switch (vector) {
    case 0x13:
      printf("int 0x13: disk service\n");
      ret = disk_service(cpu.registers[0].read_8h());

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

int disk_service(uint8_t func)
{
  printf("bios interruption: disk_service, func=%d\n", func);

  switch (func) {
    case 0x02:
      printf("bios interruption: read sector\n");
      break;
    default:
      printf("can not implement, func=0x%02x\n", func);
      break;
  }

  return 0;
}
