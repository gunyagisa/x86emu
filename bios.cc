#include "bios.h"
#include <cstdio>

void software_interrupt(CPU &cpu)
{
  uint8_t vector = cpu.get_code8();
  cpu.eip++;

  switch (vector) {
    case 0x13:
      printf("int 0x13: disk service\n");
      disk_service((cpu.registers[0] & 0xff00 )>> 8);
      break;
    default:
      printf("int 0x%02x: can not implement\n", vector);
      break;
  }
}

void disk_service(uint8_t func)
{
  printf("bios interruption: disk_service, func=%d\n", func);

  switch (funt) {
    case 0x02:
      printf("bios interruption: read sector\n");
      break;
    default:
      printf("can not implement, func=0x%02x\n", func);
      break;
  }
}
