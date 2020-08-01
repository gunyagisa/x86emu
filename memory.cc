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

void Memory::write_16(uint32_t addr, uint16_t val)
{
  memory[addr] = val & 0x00ff;
  memory[addr+1] = (val & 0xff00) >> 8;
}

void Memory::write_32(uint32_t addr, uint32_t val)
{
  for (int i = 0; i < 4; ++i) {
    memory[addr + i] = (val & 0x000000ff);
    val = val >> 8;
  }
}

uint8_t Memory::read_8(uint32_t addr)
{
  printf("read memory %x\n", memory[addr]);
    return memory[addr];
}
uint8_t Memory::read_8(Register &reg)
{
  return read_8(reg.read_32());
}

uint16_t Memory::read_16(uint16_t addr)
{
  printf("%x:%x at %x\n", memory[addr], memory[addr+1], addr);
  return (memory[addr] | memory[addr+1] << 8);
}

uint16_t Memory::read_16(Register &reg)
{
  return read_16(reg.read_16());
}



uint32_t Memory::read_32(uint32_t addr) 
{
  uint32_t ret = 0;
  for (int i = 0;i < 4;++i) {
    ret |= (memory[addr + i] << i * 8);
  }
  return ret;
}

uint32_t Memory::read_32(Register &reg)
{
  uint32_t ret = read_32(reg.read_32());
  return ret;
}
