#include "modrm.h"
#include "cpu.h"
#include <bits/stdint-uintn.h>

ModRM::ModRM()
{}

ModRM::ModRM(const uint8_t code) {
  set(code);
}

void ModRM::set(uint8_t code)
{
  mod = (0xc0 & code) >>  6;
  reg = (code & 0x38) >> 3;
  rm = code & 0x7;
}

void ModRM::parse(CPU &cpu)
{
  set(cpu.get_code8());
  cpu.eip++;

  printf("modrm: mod: %x reg: %x rm: %x\n", mod, reg, rm);

  if (mod != 3 && rm == 4) { // register
    sib = cpu.get_code8();
    cpu.eip++;
  } else if ((mod == 0 && rm == 6) || mod == 2) { // disp 32
    if (cpu.mode == PROTECTED_MODE) {
      disp32 = cpu.get_code32();
      cpu.eip += 4;
      printf("disp32:%04x\n", disp32);
    } else if (cpu.mode == REAL_MODE) {
      disp32 = cpu.get_code16();
      cpu.eip += 2;
      printf("disp16:%04x\n", disp32);
    }
  } else if (mod == 1) { // disp 8
    disp8 = cpu.get_code8();
    cpu.eip++;
    printf("disp8: %x\n", disp8);
  }

}

uint32_t ModRM::calc_address(CPU &cpu)
{
  if (cpu.mode == REAL_MODE) {
    uint16_t addr = calc_address16(cpu, *this);
    return addr;
  }
  if (mod == 0) {
    if (rm == 4) {
      printf("not implemented.\n");
      exit(0);
    } else if (rm == 5) {
      return disp32;
    } else {
      return cpu.registers[rm].read_32();;
    }
  } else if (mod == 1) {
    if (rm == 4) {
      printf("modrm mod 1 , rm 4\n");
      exit(1);
    } else {
      return cpu.registers[rm].read_32() + disp8;
    }
  } else if (mod == 2) {
    if (rm == 0) {
      return cpu.registers[reg].read_32() + disp32;
    } else if (rm == 4) {
      printf("modrm mod 3 , rm 4\n");
      exit(1);
    } else {
      return cpu.registers[rm].read_32() + disp32;
    }
  } else {
    printf("wrong modrm\n");
    exit(1);
  }
}

uint16_t calc_address16(CPU &cpu, ModRM &modrm)
{
  if (modrm.mod == 0) {
    if (modrm.rm == 0) {
      uint16_t ret = cpu.registers[3].read_16() + cpu.registers[6].read_16();
      std::cout << "calc: " << ret << std::endl;
    } else if (modrm.rm == 4) {
      printf("not implemented.\n");
      exit(0);
    } else if (modrm.rm == 5) {
      return (uint16_t) modrm.disp32;
    } else if (modrm.rm == 7) {
      return cpu.registers[3].read_16();
    } else {
      return cpu.registers[modrm.rm].read_16();;
    }
  } else if (modrm.mod == 1) {
    if (modrm.rm == 4) {
      printf("modrm mod 1 , rm 4\n");
      exit(1);
    } else {
      return cpu.registers[modrm.rm].read_16() + modrm.disp8;
    }
  } else if (modrm.mod == 2) {
    if (modrm.rm == 0) {
      return cpu.registers[3].read_16() + cpu.registers[6].read_16() + modrm.disp8;
    } else if (modrm.rm == 4) {
      printf("modrm mod 3 , rm 4\n");
      exit(1);
    } else {
      return cpu.registers[modrm.rm].read_16() + (uint16_t) modrm.disp32;
    }
  } else {
    printf("wrong modrm\n");
    exit(1);
  }
}

void ModRM::show()
{
  printf("modrm mod %x, reg %x, rm %x\n", mod, reg, rm);
}

void set_rm8(CPU &cpu, ModRM &modrm, uint8_t val)
{
  if (modrm.mod == 3) {
    if (modrm.rm <= 3) {
      cpu.registers[modrm.rm].write_8l(val);
    } else {
      cpu.registers[modrm.rm - 4].write_8h(val);
    }
  } else {
    uint32_t addr = modrm.calc_address(cpu);
    printf("write addr: 0x%x\n", addr);
    cpu.memory.write_8(addr, val);
  }
}

void set_rm16(CPU &cpu, ModRM &modrm, uint16_t val)
{
  if (modrm.mod == 3) {
    cpu.registers[modrm.rm].write_16(val);
  } else {
    uint16_t addr = calc_address16(cpu, modrm);
    cpu.memory.write_16(addr, val);
  }
}

void set_rm32(CPU &cpu, ModRM &modrm, uint32_t val)
{
  if ( modrm.mod == 3 ) {
    cpu.registers[modrm.rm].write_32(val);
  } else {
    uint32_t addr = modrm.calc_address(cpu);
    cpu.memory.write_32(addr, val);
  }
}

void set_sreg(CPU &cpu, ModRM &modrm, uint16_t val)
{
  switch (modrm.reg) {
    case 0:
      cpu.es = val;
      break;
    case 1:
      cpu.cs = val;
      break;
    case 2:
      cpu.ss = val;
      break;
    case 3:
      cpu.ds = val;
      break;
    case 4:
      cpu.fs = val;
      break;
    case 5:
      cpu.gs = val;
      break;
    default:
      printf("can not set segment register: modrm.reg %d\n", modrm.reg);
      break;
  }
}

void set_status_flag(CPU &cpu, uint32_t op1, uint32_t op2)
{
  int32_t result = op1 - op2;

  if (result > 0) {
    cpu.eflags &= 0x7fffffff;
    cpu.eflags &= ~(0x02000000);
    printf("Carry Flag Off!\n");
  } else if (result < 0) {
    cpu.eflags |= 0x80000000;
    cpu.eflags &= ~(0x02000000);
    printf("Carry Flag On!\n");
  } else if (result == 0) {
    cpu.eflags |= 0x02000000;
    printf("Zero Flag!\n");
  }
  printf("eflags: 0x%x\n", cpu.eflags);
}

uint8_t get_rm8(CPU &cpu, ModRM &modrm)
{
  if (modrm.mod == 3) {
    if (modrm.rm <= 3) {
      return cpu.registers[modrm.rm].read_8l();
    } else {
      return cpu.registers[modrm.rm - 4].read_8h();
    }
  } else {
    uint32_t addr = modrm.calc_address(cpu);
    return cpu.memory.read_8(addr);
  }
}

uint16_t get_rm16(CPU &cpu, ModRM &modrm)
{
  if (modrm.mod == 3) {
      return cpu.registers[modrm.rm].read_16();
  } else {
    uint16_t addr = modrm.calc_address(cpu);
    return cpu.memory.read_16(addr);
  }
}

uint32_t get_r32(CPU &cpu, ModRM &modrm)
{
  return cpu.registers[modrm.reg].read_32();
}

uint8_t get_r8(CPU &cpu, ModRM &modrm)
{
  if (modrm.reg < 4) {
    return cpu.registers[modrm.reg].read_8l();
  } else {
    return cpu.registers[modrm.reg].read_8h();
  }
}

uint16_t get_sreg(CPU &cpu, ModRM &modrm)
{
  switch (modrm.reg) {
    case 0:
      return cpu.es;
      break;
    case 1:
      return cpu.cs;
      break;
    case 2:
      return cpu.ss;
      break;
    case 3:
      return cpu.ds;
      break;
    case 4:
      return cpu.fs;
      break;
    case 5:
      return cpu.gs;
      break;
    default:
      printf("can not get segment register: modrm.reg %d\n", modrm.reg);
      exit(0);
      break;
  }
}
