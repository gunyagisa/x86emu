#pragma once
#include "register.h"
#include "cpu.h"

namespace Instruction32 {

  void mov_r32_imm32(Register &reg, uint32_t num);
  void add_eax_imm32(Register &reg, uint32_t num);
  void add_rm32_imm8(Register &dst_reg, uint8_t num);
  void mov_rm32_r32(CPU &cpu);
}

namespace Instruction16 {
  void jmp_short(CPU &cpu);
  void mov_r16_imm16(CPU &cpu);
  void add_rm16_imm8(CPU &cpu);
  void add_rm8_imm8(CPU &cpu);
  void jb(CPU &cpu);
  void jbe(CPU &cpu);
  void cmp(CPU &cpu);
  void mov_rm8_r8(CPU &cpu);
  void mov_sreg_rm16(CPU &cpu);
  void mov_rm16_sreg(CPU &cpu);
  void jnc(CPU &cpu);
}
