#include "memory.h"
#include "register.h"

Memory::Memory() : size(1024)
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
  memory[addr] = val;
}

uint8_t Memory::read_8(uint32_t addr)
{
  printf("read memory %x\n", memory[addr]);
    return memory[addr];
}
uint8_t Memory::read_8(Register &reg)
{
  printf("read memory %x\n", memory[reg]);
  return memory[reg];
}

uint16_t Memory::read_16(uint16_t addr)
{
  return (memory[addr] | memory[addr+1] << 8);
}

uint32_t Memory::read_32(uint32_t addr) 
{
  uint32_t ret = 0;
  for (int i = 0;i < 4;++i) {
    ret |= (memory[addr + i] << i * 4);
  }
  return ret;
}

uint32_t Memory::read_32(Register &reg)
{
  uint32_t ret = read_32((int)reg);
  return ret;
}
