#include "modrm.h"

ModRM::ModRM(const uint8_t code)
{
  mod = code >> 6;
  reg = (code >> 3) & 0x7;
  rm = code & 0x7;
}

void ModRM::parse(CPU &cpu)
{
  cpu.eip++;

  if (mod != 3 && rm == 4) { // register
    sib = cpu.get_code8();
    cpu.eip++;
  } else if ((mod == 0 && rm == 5) || mod == 2) { // disp 32
    disp32 = cpu.get_code32();
    cpu.eip += 4;
  } else if (mod == 1) { // disp 8
    disp8 = cpu.get_code8();
    cpu.eip++;
  }

}

uint32_t ModRM::calc_address(CPU &cpu)
{
  if (mod == 0) {
    if (rm == 4) {
      printf("not implemented.\n");
      exit(0);
    } else if (rm == 5) {
      return disp32;
    } else {
      return cpu.registers[rm];
    }
  } else if (mod == 1) {
    if (rm == 4) {
      printf("modrm mod 1 , rm 4\n");
      exit(1);
    } else {
      return cpu.registers[rm] + disp8;
    }
  } else if (mod == 2) {
    if (rm == 4) {
      printf("modrm mod 3 , rm 4\n");
      exit(1);
    } else {
      return cpu.registers[rm] + disp32;
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

void set_rm32(CPU &cpu, ModRM &modrm, uint32_t val)
{
  if ( modrm.mod == 3 ) {
    cpu.registers[modrm.rm] = val;
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


uint16_t get_rm16(CPU &cpu, ModRM &modrm)
{
  if (modrm.mod == 3) {
    if (modrm.rm <= 3) {
      return cpu.registers[modrm.rm] & 0xffff;
    } else {
      return cpu.registers[modrm.rm - 4] >> 4;
    }
  } else {
    uint16_t addr = modrm.calc_address(cpu);
    return cpu.memory.read_16(addr);
  }
}

uint32_t get_r32(CPU &cpu, ModRM &modrm)
{
  return cpu.registers[modrm.reg];
}
