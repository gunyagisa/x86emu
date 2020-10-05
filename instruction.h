#pragma once
#include "register.h"
#include "cpu.h"
#include "modrm.h"

extern ModRM modrm;

namespace Instruction32 {

  void mov_r32_imm32(Register &reg, uint32_t num);
  void add_eax_imm32(Register &reg, uint32_t num);
  void add_rm32_imm8(Register &dst_reg, uint8_t num);
  void mov_rm32_r32(CPU &cpu);
  void call(CPU *cpu);
  void ret(CPU *cpu);
}

namespace Instruction16 {
  void and_rm16_imm8(CPU &cpu);
  void mov_r32_cr(CPU &cpu);
  void mov_cr_r32(CPU &cpu);
  void ret_imm16(CPU &cpu);
  void pop_r(CPU &cpu);
  void lgdt(CPU &cpu);
  void add_rm8_r8(CPU *cpu);
  void or_r8_rm8(CPU &cpu);
  void mov_rm8_imm8(CPU *cpu);
  void or_rm16_imm8(CPU &cpu);
  void cmp_eax(CPU *cpu);
  void inc(CPU *cpu, int reg);
  void jmp_short(CPU &cpu);
  void mov_r16_imm16(CPU &cpu);
  void add_rm16_imm8(CPU &cpu);
  void add_rm8_imm8(CPU &cpu);
  void jb(CPU &cpu);
  void jbe(CPU &cpu);
  void cmp(CPU &cpu);
  void mov_rm_r(CPU *cpu);
  void mov_rm8_r8(CPU &cpu);
  void mov_sreg_rm16(CPU &cpu);
  void mov_rm16_sreg(CPU &cpu);
  void jnc(CPU &cpu);
  void jg(CPU *cpu);
  void jmp_rel16(CPU *cpu);
  void div_r32(CPU *cpu);
  void hlt(CPU *cpu);
  void cmp_rm_imm(CPU *cpu);
}
