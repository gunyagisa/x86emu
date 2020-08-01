#pragma once
#include <iostream>
#include "cpu.h"

struct ModRM {
  uint8_t mod: 2;

  union {
    uint8_t reg: 3 ;
    uint8_t ext: 3;
  };

  uint8_t rm: 3;

  uint8_t sib: 2;

  union {
    int8_t disp8;
    uint32_t disp32;
  };

  ModRM(uint8_t modrm);

  void parse(CPU &cpu);
  uint32_t calc_address(CPU &cpu);

  void show();
};

void set_rm16(CPU &cpu, ModRM &modrm, uint16_t val);
void set_rm32(CPU &cpu, ModRM &modrm, uint32_t val);
void set_sreg(CPU &cpu, ModRM &modrm, uint16_t val);


uint16_t get_rm16(CPU &cpu, ModRM &modrm);
uint32_t get_r32(CPU &cpu, ModRM &modrm);
uint16_t get_sreg(CPU &cpu, ModRM &modrm);

