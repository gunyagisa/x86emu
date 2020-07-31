#pragma once
#include "register.h"
#include "cpu.h"

void mov_r32_imm32(Register &reg, uint32_t num);
void add_eax_imm32(Register &reg, uint32_t num);
void add_rm32_imm8(Register &dst_reg, uint8_t num);
void mov_rm32_r32(CPU &cpu);
