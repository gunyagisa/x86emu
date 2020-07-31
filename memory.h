#pragma once

#include "register.h"

#include <iostream>
#include <bitset>

class Memory {
  private:
    int32_t size;
    uint8_t *memory;
    uint8_t read_8(uint32_t addr);
    uint32_t read_32(uint32_t addr);

  public:
    Memory();
    Memory(uint32_t);
    ~Memory();

    void write(uint32_t addr, uint8_t data[], uint32_t size);
    void write_32(uint32_t addr, uint32_t val);

    uint8_t read_8(Register &reg);

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
