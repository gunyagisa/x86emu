#include "memory.h"
#include "cpu.h"
#include "register.h"
#include <bits/stdint-uintn.h>

Memory::Memory() : size(0xfffffff)
{
  memory = new uint8_t[size];
}

Memory::Memory(uint32_t size) : size(size)
{
  memory = new uint8_t[size];
}

Memory::~Memory()
{
  delete memory;
}

void Memory::write(uint32_t addr, uint8_t data[], uint32_t size)
{
  for (int i = 0;i < size;++i) {
    memory[addr + i] = data[i];
  }
}

void Memory::write_32(uint32_t addr, uint32_t val)
{
  for (int i = 0; i < 4; ++i) {
    write_8(addr + i, val >> (i * 8));
  }
}

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
    return cpu.ds * 16 + addr;
  } else {
    if (is_segment(cpu)) {
    } else if (is_paging(cpu)) {
    }
  }
}
