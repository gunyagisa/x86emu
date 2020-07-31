#pragma once
#include <iostream>
#include "cpu.h"

struct ModRM {
  uint8_t mod: 2;
  uint8_t reg: 3 ;
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
