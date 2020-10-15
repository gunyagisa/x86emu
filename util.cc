#include "cpu.h"
#include <bits/stdint-uintn.h>
#include <cstdint>


bool is_segment(CPU &cpu) {
  return cpu.manager.segment;
}

bool is_paging(CPU  &cpu) {
  return false;
}

uint32_t get_real_addr(uint32_t addr, CPU &cpu)
{
  if (cpu.mode == REAL_MODE) {
    // segment register addressing 
    printf("REAL_MODE access\n");
    return cpu.ds * 16 + addr;
  } else {
    if (is_segment(cpu)) {
      struct GDT *gdt = (struct GDT *) ((uintptr_t)cpu.gdtr + cpu.ds);
      uint32_t base = gdt->base_hi << 24 | gdt->base_mid << 16 | gdt->base_low;
      printf("segment %d: 0x%08x\n", cpu.ds, base + addr);
      return base + addr;
    }
    if (is_paging(cpu)) {
    }
  }

  return 0;
}

void set_protected_mode(CPU &cpu)
{
  cpu.mode = PROTECTED_MODE;
}

void set_manager(CPU &cpu, const char *file)
{
  cpu.manager.disk_name = file;
}

void load_ipl(unsigned char *buf, const char *file)
{
  FILE *fp;

  fp = fopen(file, "rb");

  if (fp == NULL) {
    perror(__FUNCTION__);
    exit(1);
  }

  fread(buf, sizeof(uint8_t), 512, fp);
  fclose(fp);
}
