#include "cpu.h"
#include "instruction.h"
#include "modrm.h"
#include "bios.h"
#include <bits/stdint-uintn.h>
#include <cstdio>
#include <cstdlib>
#include <ostream>

extern ModRM modrm;

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

void CPU::decoder()
{
  for (;;) {
    using namespace Instruction16;
    uint8_t code = get_code8();
    printf("code=%02x, eip=0x%08x\n", code, (uint32_t)eip);
    eip++;

no_eip:

    if (mode == PROTECTED_MODE) {
      using namespace Instruction32;
      if (0xb8 <= code && code <= 0xbf) {
        uint32_t num = get_code32();
        eip += 4;
        registers[code - 0xb8] = num;
        std::cout << "mov :" << num << std::endl;
        continue;
      } else if ( code == 0x05 ) {
        uint32_t num = get_code32();
        eip += 4;
        add_eax_imm32(registers[0], num);
        continue;
      } else if (code == 0x74) {
        if (is_zf()) {
          jmp_short(*this);
        } else {
          eip++;
        }
        continue;
      } else if (code == 0x75) {
        std::cout << "ZF==" << is_zf() << std::endl;
        if (!(is_zf())) {
          jmp_short(*this);
        } else {
          eip++;
        }
        continue;
      } else if ( code == 0x83 ) {
        modrm.parse(*this);
        if (modrm.ext == 0) {
          uint32_t op1 = get_rm32(*this);
          uint8_t op2 = get_code8();
          eip++;

          printf("ADD op1 %d, op2 %d\n", op1, op2);
          set_rm32(*this, op1 + op2);
          continue;
        } else if (modrm.ext == 5) {
          sub_rm32_imm8(*this);
          continue;
        }
      } else if ( code == 0x89 ) {
        mov_rm32_r32(*this);
        continue;
      } else if (code == 0x81) {
        cmp_rm_imm(this);
        continue;
      } else if (code == 0x8b) {
        mov_r32_rm32(*this);
        continue;
      } else if (code == 0xea) {
        printf("jumpf\n");
        fflush(stdout);
        jumpf(*this);
        continue;
      }
    }
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
    } else if (0x58 <= code && code <= 0x5f) {
      pop_r(*this);
    } else {
      switch (code) {
        case 0x00:
          add_rm8_r8(this);
          break;
        case 0x0a:
          or_r8_rm8(*this);
          break;
        case 0x0f:
          code = get_code8();
          eip += 1;

          if (code == 0x01) {
            std::cout << "eip" << eip << std::endl;
            modrm.parse(*this);
            std::cout << "eip" << eip << std::endl;
            // lgdt
            lgdt(*this);
          } else if (code == 0x20) {
            // mov r32, cr
            mov_r32_cr(*this);
          } else if (code == 0x22) {
            mov_cr_r32(*this);
          }
          break;
        case 0x3d:
          cmp_eax(this);
          break;
        case 0xc2:
          ret_imm16(*this);
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
          modrm.parse(*this);
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
          modrm.parse(*this);
          switch (modrm.ext) {
            case 0:
              add_rm16_imm8(*this);
              break;
            case 1:
              or_rm16_imm8(*this);
              break;
            case 4:
              and_rm16_imm8(*this);
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
        case 0x66:
          break;
        default:
          fprintf(stderr, "[e] can not implement code: 0x%02x\n", code);
          fprintf(stderr, "eip: 0x%08x\n", (uint32_t) eip);
          exit(1);
          break;
      } 
    } 
  }
}
