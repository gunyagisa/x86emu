#pragma once
#include <iostream>

struct ModRM {
  uint8_t mod: 2;
  uint8_t reg: 3 ;
  uint8_t rm: 3;

  ModRM(uint8_t modrm);
};
