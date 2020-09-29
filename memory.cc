#include "memory.h"
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

void Memory::write_8(uint32_t addr, uint8_t val)
{
  memory[addr] = val;
}

void Memory::write_16(uint32_t addr, uint16_t val)
{
  memory[addr] = val & 0x00ff;
  memory[addr+1] = (val & 0xff00) >> 8;
}

void Memory::write_32(uint32_t addr, uint32_t val)
{
  for (int i = 0; i < 4; ++i) {
    write_8(addr + i, val >> (i * 8));
  }
}

