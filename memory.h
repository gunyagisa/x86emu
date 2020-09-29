#pragma once

#include "register.h"

#include <bits/stdint-uintn.h>
#include <iostream>
#include <bitset>

class Memory {
  private:
    int32_t size;
    uint8_t *memory;

  public:
    Memory();
    Memory(uint32_t);
    ~Memory();

    operator uint8_t * () { return memory; }

    void write(uint32_t addr, uint8_t data[], uint32_t size);
    void write_8(uint32_t addr, uint8_t val);
    void write_16(uint32_t  addr, uint16_t val);
    void write_32(uint32_t addr, uint32_t val);

    uint8_t read_8(uint32_t addr);
    uint16_t read_16(uint16_t addr);
    uint32_t read_32(uint32_t addr);

    uint8_t read_8(Register &reg);
    uint16_t read_16(Register &reg);

    uint32_t read_32(Register &reg);

    void show_memory() const
    {
      for (int i = 0;i < size;++i) {
        if (i % 8 == 0) std::cout << i  << ":";
        std::cout << std::bitset<8>(memory[i]) << " ";
        if (i % 8 == 7) std::cout << std::endl;
      }
    }
};

inline uint8_t Memory::read_8(uint32_t addr)
{
  return memory[addr];
}
inline uint8_t Memory::read_8(Register &reg)
{
  return read_8(reg.read_32());
}

inline uint16_t Memory::read_16(uint16_t addr)
{
  return (memory[addr] | memory[addr+1] << 8);
}

inline uint16_t Memory::read_16(Register &reg)
{
  return read_16(reg.read_16());
}



inline uint32_t Memory::read_32(uint32_t addr) 
{
  uint32_t ret = 0;
  for (int i = 0;i < 4;++i) {
    ret |= (memory[addr + i] << i * 8);
  }
  return ret;
}

inline uint32_t Memory::read_32(Register &reg)
{
  uint32_t ret = read_32(reg.read_32());
  return ret;
}
