#include "instruction.h"
#include "register.h"
#include "modrm.h"
#include "cpu.h"
#include <bits/stdint-uintn.h>

namespace Instruction32 {

  // 0x
  void mov_r32_imm32(Register &reg, uint32_t num)
  {
    reg = num;
  }

  // 0x89
  void mov_rm32_r32(CPU &cpu)
  {
    ModRM modrm{cpu.get_code8()};
    modrm.parse(cpu);
    uint32_t val = get_r32(cpu, modrm);
    printf("val: %d\n", val);
    set_rm32(cpu, modrm, val);
  }


  // 0x05 id
  void add_eax_imm32(Register &reg, uint32_t num)
  {
    reg += num;
  }

  // 0x83 add
  void add_rm32_imm8(Register &dst_reg, uint8_t num)
  {
    dst_reg += num;
  }

}

namespace Instruction16 {
  // 0xeb JMP
  void jmp_short(CPU &cpu)
  {
    int8_t rel8 = cpu.get_code8();
    cpu.eip++;
    printf("rel8 %x\n", rel8);
    cpu.eip += cpu.cs * 16 + rel8;
  }

  // 0xb8 dword, mov ax dword
  void mov_r16_imm16(CPU &cpu)
  {
    uint16_t imm16 = cpu.get_code16();
    cpu.eip += 2;
    cpu.registers[0] = imm16;
  }

  void add_rm16_imm8(CPU &cpu)
  {
    ModRM modrm;
    modrm.parse(cpu);
    uint16_t op2 = cpu.get_code8();
    cpu.eip++;
    uint16_t op1 = get_rm16(cpu, modrm);
    set_rm16(cpu, modrm, op1 + op2);
  }

  // 0x8c
  void mov_rm16_sreg(CPU &cpu)
  {
    ModRM modrm;
    modrm.parse(cpu);
    uint16_t val = get_sreg(cpu, modrm);
    printf("val 0x%x\n", val);
    set_rm16(cpu, modrm, val);
  }


  // 0x8e
  void mov_sreg_rm16(CPU &cpu)
  {
    ModRM modrm;
    modrm.parse(cpu);
    uint16_t val = get_rm16(cpu, modrm);
    printf("val 0x%x\n", val);
    set_sreg(cpu, modrm, val);

    cpu.show_segment_registers();
  }

  // 0x73
  void jnc(CPU &cpu)
  {
    printf("eflags: %08x\n", cpu.eflags);
    if (!(cpu.is_cf())) {
      jmp_short(cpu);
    } else {
      cpu.eip++;
    }
  }

}
