#include "instruction.h"
#include "register.h"
#include "modrm.h"
#include "cpu.h"

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
  uint32_t val = cpu.get_r32(modrm);
  printf("val: %d\n", val);
  cpu.set_rm32(modrm, val);
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

