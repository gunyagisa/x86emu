#include "modrm.h"

ModRM::ModRM(const uint8_t modrm)
{
  mod = modrm >> 6;
  reg = modrm & 0x38 >> 3;
  rm = modrm & 0x7;
}
