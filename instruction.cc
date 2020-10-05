#include "instruction.h"
#include "cpu.h"
#include "modrm.h"
#include <bits/stdint-uintn.h>
#include <cstdio>
#include <ostream>

namespace Instruction32 {

  // 0x
  void mov_r32_imm32(Register &reg, uint32_t num)
  {
    reg = num;
  }

  // 0x89
  void mov_rm32_r32(CPU &cpu)
  {
    modrm.parse(cpu);
    uint32_t val = get_r32(cpu);
    set_rm32(cpu, val);
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

  // 0xe8
  void call(CPU *cpu)
  {
    uint32_t dst = cpu->get_code32();
    cpu->eip += 4;

    cpu->eip = 0xc222;
  }

  void ret(CPU *cpu)
  {
    cpu->eip = 0xc214;
  }

}

namespace Instruction16 {
  // 0x00 add
  void add_rm8_r8(CPU *cpu)
  {
    modrm.parse(*cpu);
    uint8_t op2 = get_r8(*cpu);
    uint8_t op1 = get_rm8(*cpu);
    set_rm8(*cpu, op1 + op2);
  }

  // 0a
  void or_r8_rm8(CPU &cpu)
  {
    modrm.parse(cpu);
    uint8_t op1, op2;
    op1 = get_r8(cpu);
    op2 = get_rm8(cpu);

    set_r8(cpu, op1 | op2);
  }


  // 0x0f lgdt
  void lgdt(CPU &cpu)
  {
    modrm.parse(cpu);
    uint32_t gdt = get_rm16(cpu);
    cpu.gdtr = gdt;
    printf("load to gdtr: 0x%08x\n", (uint32_t)cpu.gdtr);
    cpu.manager.segment = true;
  }

  void mov_r32_cr(CPU &cpu)
  {
    modrm.parse(cpu);
    int op = get_cr(cpu);
    set_rm32(cpu, op);
  }

  void mov_cr_r32(CPU &cpu)
  {
    modrm.parse(cpu);
    uint32_t op = get_r32(cpu);
    set_cr(cpu, op);
  }

  // 0x3d
  void cmp_eax(CPU *cpu) 
  {
    uint32_t op = cpu->get_code32();
    cpu->eip += 4;
    uint16_t op2 = cpu->registers[0].read_16();
    set_status_flag(*cpu, op, op2);
  }

  // 0x40 inc
  void inc(CPU *cpu, int reg)
  {
    if (cpu->mode == REAL_MODE) {
      uint16_t tmp = cpu->registers[reg].read_16();
      cpu->registers[reg].write_16(tmp + 1);
    } else if (cpu->mode == PROTECTED_MODE) {
      uint32_t tmp = cpu->registers[reg].read_32();
      cpu->registers[reg].write_32(tmp + 1);
    }
  }

  // 0x5a
  void pop_r(CPU &cpu)
  {
    uint32_t val = get_r(cpu);
    if (cpu.mode == REAL_MODE) {
      cpu.memory.write_16(cpu.registers[cpu.ESP], val);
    }
  }

  void mov_rm_r(CPU *cpu) 
  {
    if (cpu->mode == PROTECTED_MODE) {
      Instruction32::mov_rm32_r32(*cpu);
      return;
    }
    modrm.parse(*cpu);

    uint16_t op = get_r(*cpu);
    set_rm(*cpu, op);
  }

  // 0xc2 ret imm8
  void ret_imm16(CPU &cpu)
  {
    uint16_t near_addr = cpu.get_code16();
    cpu.eip += 2;

    cpu.registers[cpu.ESP] = get_real_addr(near_addr, cpu);
    cpu.registers[cpu.ESP] += -2;
  }

  //0xc6 mov
  void mov_rm8_imm8(CPU *cpu)
  {
    modrm.parse(*cpu);

    uint8_t op = cpu->get_code8();
    cpu->eip++;
    set_rm8(*cpu, op);
  }

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
    modrm.parse(cpu);
    uint16_t imm16 = cpu.get_code16();
    cpu.eip += 2;
    cpu.registers[0] = imm16;
  }

  // 0x83 ext
  void add_rm16_imm8(CPU &cpu)
  {
    uint16_t op2 = cpu.get_code8();
    cpu.eip++;
    uint16_t op1 = get_rm16(cpu);
    set_rm16(cpu, op1 + op2);
  }

  void or_rm16_imm8(CPU &cpu)
  {
    uint16_t op1 = get_rm16(cpu);
    uint8_t op2 = cpu.get_code8();
    cpu.eip++;

    set_rm16(cpu, op1 | op2);
  }

  void and_rm16_imm8(CPU &cpu)
  {
    uint16_t op1 = get_rm16(cpu);
    uint16_t op2 = cpu.get_code8();
    cpu.eip++;
    set_rm16(cpu, op1 & op2);
  }

  // 0x72
  void jb(CPU &cpu)
  {
    if (cpu.is_cf()) {
      jmp_short(cpu);
    } else {
      cpu.eip++;
    }
  }

  // 0x76
  void jbe(CPU &cpu)
  {
    std::cout << "jbe CF==" << cpu.is_cf() << std::endl;
    // CF = 1 or ZF = 1
    if (cpu.is_cf() || cpu.is_zf()) {
      jmp_short(cpu);
    } else {
      cpu.eip++;
    }
  }


  // 0x80
  void add_rm8_imm8(CPU &cpu)
  {
    uint8_t val = cpu.get_code8();
    cpu.eip++;
    uint8_t val2 = get_rm8(cpu);
    set_rm8(cpu, val + val2);
  }

  void cmp(CPU &cpu)
  {
    uint8_t op1 = get_rm8(cpu);
    uint8_t op2 = cpu.get_code8();
    cpu.eip++;

    printf("compare %d and %d\n", op1, op2);

    set_status_flag(cpu, op1, op2);
  }

  // 0x88
  void mov_rm8_r8(CPU &cpu)
  {
    modrm.parse(cpu);

    uint8_t val = get_r8(cpu);
    set_rm8(cpu, val);
  }


  // 0x8c
  void mov_rm16_sreg(CPU &cpu)
  {
    modrm.parse(cpu);
    uint16_t val = get_sreg(cpu);
    set_rm16(cpu, val);
  }


  // 0x8e
  void mov_sreg_rm16(CPU &cpu)
  {
    modrm.parse(cpu);
    uint16_t val = get_rm16(cpu);
    set_sreg(cpu, val);
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

  //0x7f
  void jg(CPU *cpu) {
    if (cpu->is_cf() == false) {
      jmp_short(*cpu);
    } else {
      cpu->eip += 2;
    }
  }

  void jmp_rel16(CPU *cpu) {
    uint16_t rel16 = cpu->get_code16();
    printf("JMP rel16: %x\n", rel16);
    cpu->eip += 2;
    cpu->eip += rel16;
  }

  // 0x81
  void cmp_rm_imm(CPU *cpu)
  {
    modrm.parse(*cpu);

    uint32_t op2 = cpu->get_code32();
    cpu->eip += 4;
    uint32_t op1 = get_rm32(*cpu);

    printf("compare 0x%08x and 0x%08x\n", op1, op2);

    set_status_flag(*cpu, op1, op2);
  }


  // 0xf7
  void div_r32(CPU *cpu)
  {
    modrm.parse(*cpu);
    uint32_t op = get_rm32(*cpu);
    uint32_t a = cpu->registers[0].read_32();
    uint32_t r = a % op;
    uint16_t p = a / op;
    cpu->registers[0].write_32(p);
    cpu->registers[2].write_32(r);
  }

  void hlt(CPU *cpu) {
    fprintf(stderr, "HLT\n");
    return;
  }
}
