#include "cpu.h"

CPU::CPU() : memory(), eip()
{ }
CPU::CPU(uint8_t data[], uint32_t size, uint32_t addr)
  : eip(addr)
{
  memory.write(addr, data, size);
}

CPU::~CPU() {}

void CPU::show_registers()
{
  for (int i = 0;i < 8;i++) {
    std::cout << registers[i] << std::endl;
  }
}

void CPU::decoder()
{
  for (;;) {
    uint8_t code = memory.read_8(eip++);
    if (0xb8 <= code && code <= 0xbf) {
      uint32_t num = memory.read_32(eip);
      eip += 4;
      mov_r32_imm32(code - 0xb8, num);
    }
  }
}

void CPU::mov_r32_imm32(uint8_t reg, uint32_t num)
{
  registers[reg] += num;
}
