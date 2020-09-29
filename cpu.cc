#include "cpu.h"
#include "instruction.h"
#include "modrm.h"
#include "bios.h"
#include <bits/stdint-uintn.h>
#include <cstdio>
#include <cstdlib>
#include <ostream>

CPU::CPU()
  : memory(), eip()
{ }


CPU::CPU(uint8_t data[], uint32_t size, uint32_t addr)
  : memory(), eip(addr) 
{ 
  memory.write(addr, data, size);
  cs = 0;
  ds = 0;
  ss = 0;
  es = 0;
  fs = 0;
  gs = 0;
  mode = REAL_MODE;
}

CPU::~CPU() {}

void CPU::show_registers()
{
  for (int i = 0;i < 8;i++) {
    std::cout << registers[i] << std::endl;
  }

  std::cout << "eip: " << eip << std::endl;
}

void CPU::trans2protect()
{
  mode = PROTECTED_MODE;

  printf("trans2protect\n");
}

void CPU::show_segment_registers()
{
  printf("cs = 0x%x\n", cs);
  printf("ds = 0x%x\n", ds);
  printf("ss = 0x%x\n", ss);
  printf("es = 0x%x\n", es);
  printf("fs = 0x%x\n", fs);
  printf("gs = 0x%x\n", gs);
}

uint8_t CPU::get_code8()
{
  uint8_t code = memory.read_8(eip);
  return code;
}

uint16_t CPU::get_code16()
{
  uint16_t code = memory.read_16(eip);
  return code;
}

uint32_t CPU::get_code32()
{
  uint32_t code = memory.read_32(eip);
  return code;
}

bool CPU::is_cf()
{
  if ((eflags & 0x80000000) >> 31 == 1)
    return true;
  else 
    return false;
}

bool CPU::is_zf()
{
  if ((eflags & 0x02000000) >> 25 == 1)
    return true;
  else 
    return false;
}

void CPU::decoder()
{
  for (;;) {
    using namespace Instruction16;
    uint8_t code = get_code8();
    printf("code=%02x, eip=0x%08x\n", code, (uint32_t)eip);
    eip++;

    if (0xb0 <= code && code <= 0xb7) {
      uint8_t val = get_code8();
      eip++;
      if (code - 0xb0 <= 3) {
        registers[code - 0xb0].write_8l(val);
      } else {
        registers[code - 0xb0 - 4].write_8h(val);
      }
    } else if (mode == REAL_MODE && 0xb8 <= code && code <= 0xbf) {
      uint16_t val = get_code16();
      eip += 2;
      registers[code - 0xb8].write_16(val);
    } else if (0x40 <= code && code <= 0x47) {
      inc(this, code - 0x40);
    } else {
      ModRM modrm;

      switch (code) {
        case 0x00:
          add_rm8_r8(this);
          break;
        case 0x3d:
          cmp_eax(this);
          break;
        case 0xeb:
          jmp_short(*this);
          break;
        case 0xb8:
          mov_r16_imm16(*this);
          break;
        case 0xc6:
          mov_rm8_imm8(this);
          break;
        case 0x76:
          jbe(*this);
          break;
        case 0x80:
          modrm.set(get_code8());

          if (modrm.ext == 0) {
            add_rm8_imm8(*this);
          } else if (modrm.ext == 7) {
            cmp(*this);
          } else {
            printf("[0x80]: unknown ext:0x%x\n", modrm.ext);
          }

          break;
        case 0x89:
          mov_rm_r(this);
          break;
        case 0x8c:
          mov_rm16_sreg(*this);
          break;
        case 0x8e:
          mov_sreg_rm16(*this);
          break;
        case 0xcd: // int
          if (get_code8() == 0x13) {
            software_interrupt(*this);
          }
          break;
        case 0x72:
          jb(*this);
          break;
        case 0x73:
          jnc(*this);
          break;
        case 0x7f:
          jg(this);
          break;
        case 0x83:
          modrm.set(get_code8());
          switch (modrm.ext) {
            case 0:
              add_rm16_imm8(*this);
              break;
            case 7:
              break;
            default:
              break;
          }
          break;
        case 0x88:
          mov_rm8_r8(*this);
          break;
        case 0xe8:
          Instruction32::call(this);
          break;
        case 0xc3:
          Instruction32::ret(this);
          break;
        case 0xe9:
          jmp_rel16(this);
          break;
        case 0xf4:
          hlt(this);
          break;
        case 0xf7:
          div_r32(this);
          break;
        default:
          if (mode == PROTECTED_MODE) {
            using namespace Instruction32;
            if (0xb8 <= code && code <= 0xbf) {
              std::cout << "mov" << std::endl;
              uint32_t num = memory.read_32(eip);
              eip += 4;
              mov_r32_imm32(registers[code - 0xb8], num);
            } else if ( code == 0x05 ) {
              uint32_t num = get_code32();
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
            } else if (code == 0x81) {
              cmp_rm_imm(this);
            } else {
              std::cout << "[E] can not implement: opecode "
                << std::showbase << std::hex << (int)code
                << ", eip: " << eip << std::noshowbase << std::endl;
              show_registers();
              exit(0);
            }
          } else {
            show_registers();
            std::cout << "[E] can not implement: opecode "
              << std::showbase << std::hex << (int)code
              << ", eip: " << eip << std::noshowbase << std::endl;
            show_registers();
            exit(1);
            break;
          }
      } 
    } 
  }
}
