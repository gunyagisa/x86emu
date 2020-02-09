#pragma once
#include "register.h"

class Instruction {
  public:
    static void mov_r32_imm32(Register &reg, uint32_t num);
};
