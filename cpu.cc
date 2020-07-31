#include "cpu.h"
#include "instruction.h"
#include "modrm.h"

CPU::CPU()
  : memory(), eip()
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

uint8_t CPU::get_code8()
{
  uint8_t code = memory.read_8(eip);
  return code;
}

uint32_t CPU::get_code32()
{
  uint32_t code = memory.read_32(eip);
  return code;
}

void CPU::set_rm32(ModRM &modrm, uint32_t val)
{
  if ( modrm.mod == 3 ) {
    registers[modrm.rm] = val;
  } else {
    uint32_t addr = modrm.calc_address(*this);
    memory.write_32(addr, val);
  }
}

uint32_t CPU::get_r32(ModRM &modrm) {
  return registers[modrm.reg];
}


void CPU::decoder()
{
  for (;;) {
    uint8_t code = memory.read_8(eip);
    eip++;
    if (0xb8 <= code && code <= 0xbf) {
      std::cout << "mov" << std::endl;
      uint32_t num = memory.read_32(eip);
      eip += 4;
      mov_r32_imm32(registers[code - 0xb8], num);
    } else if ( code == 0x05 ) {
      uint32_t num = memory.read_32(eip);
      eip += 4;
      add_eax_imm32(registers[0], num);
     } else if ( code == 0x83 ) {
      std::cout << "add" << std::endl;
      ModRM modrm{memory.read_8(eip)};
      eip++;
      uint8_t num = memory.read_8(eip);
      eip++;
      add_rm32_imm8(registers[modrm.rm], num);
     } else if ( code == 0x89 ) {
       mov_rm32_r32(*this);
       std::cout << "mov_rm32_r32" << std::endl;
    } else {
      std::cout << "[E] can not implement: opecode "
        << std::showbase << std::hex << (int)code
        << ", eip: " << (int)eip << std::noshowbase << std::endl;
      break;
    }
  }
}
