#include "cpu.h"
#include "instruction.h"
#include "modrm.h"

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
    uint8_t code = memory.read_8(eip);
    if (0xb8 <= code && code <= 0xbf) {
      std::cout << "mov" << std::endl;
      uint32_t num = memory.read_32(eip);
      Instruction::mov_r32_imm32(registers[code - 0xb8], num);
    } else if ( code == 0x05 ) {
      uint32_t num = memory.read_32(eip);
      Instruction::add_eax_imm32(registers[0], num);
     } else if ( code == 0x83 ) {
      std::cout << "add" << std::endl;
      ModRM modrm{memory.read_8(eip)};
      uint8_t num = memory.read_8(eip);
      Instruction::add_rm32_imm8(registers[modrm.rm], num);
    } else {
      std::cout << "[E] can not implement: opecode "
        << std::showbase << std::hex << (int)code
        << ", eip: " << (int)eip << std::noshowbase << std::endl;
      break;
    }
  }
}
