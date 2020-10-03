#pragma once
#include <bits/stdint-uintn.h>
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

  ModRM();
  ModRM(uint8_t modrm);

  void set(uint8_t code);

  void parse(CPU &cpu);
  uint32_t calc_address(CPU &cpu);

  void show();
};

uint16_t calc_address16(CPU &cpu);

void set_rm(CPU &cpu, uint32_t val);
void set_rm8(CPU &cpu, uint8_t val);
void set_rm16(CPU &cpu, uint16_t val);
void set_rm32(CPU &cpu, uint32_t val);
void set_sreg(CPU &cpu, uint16_t val);
void set_status_flag(CPU &cpu, uint32_t op1, uint32_t op2);


uint8_t get_rm8(CPU &cpu);
uint16_t get_rm16(CPU &cpu);
uint32_t get_rm32(CPU &cpu);

void set_r8(CPU &cpu, uint8_t val);

uint32_t get_r(CPU &cpu);
uint32_t get_r32(CPU &cpu);
uint16_t get_r16(CPU &cpu);
uint8_t get_r8(CPU &cpu);
uint16_t get_sreg(CPU &cpu);
