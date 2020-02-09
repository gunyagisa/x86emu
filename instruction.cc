#include "instruction.h"
#include "register.h"

void Instruction::mov_r32_imm32(Register &reg, uint32_t num)
{
  reg += num;
}
