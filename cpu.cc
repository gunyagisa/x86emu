#include "cpu.h"

CPU::CPU() : memory(), eip()
{
  for (int i = 0;i < 8;++i) {
    registers[i].setname(registers_name[i]);
  }
}

CPU::~CPU() {}
