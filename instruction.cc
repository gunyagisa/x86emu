#include "instruction.h"
#include "register.h"

// 0x
void Instruction::mov_r32_imm32(Register &reg, uint32_t num)
{
  reg = num;
}


// 0x05 id
void Instruction::add_eax_imm32(Register &reg, uint32_t num)
{
  reg += num;
}
  
