#pragma once
#include "memory.h"
#include "register.h"

#include <bits/stdint-uintn.h>
#include <vector>

#define DEFAULT_START_UP_ADDRESS 0x7c00

#define REAL_MODE 0
#define PROTECTED_MODE 1

struct GDT {
  uint16_t limit_low, base_low;
  uint8_t base_mid;
  uint8_t type : 4;
  uint8_t flag : 1;
  uint8_t dpl : 2;
  uint8_t present_flag : 1;
  uint8_t limit_hi : 4;
  uint8_t avl : 1;
  uint8_t db : 1;
  uint8_t granularity : 1;
  uint8_t base_hi;
};

class CPU {
  public:
    struct manager {
      std::string disk_name;
      bool segment = false;
    } manager;


    Memory memory; 
    Register registers[8];
    Register eip;
    Register cr[8];
    uint16_t cs, ds, es, ss, fs, gs;
    uint32_t eflags;

    enum registers {EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI, REGISTER_COUNT};

    Register gdtr;

    struct LDTR {
      uint16_t limit;
      uint32_t base;
    } ldtr;

    struct IDTR {
      uint16_t limit;
      uint32_t base;
    } idtr;

    uint8_t mode;


    CPU();
    CPU(uint8_t data[], uint32_t size, uint32_t addr = DEFAULT_START_UP_ADDRESS);
    ~CPU();

    void run() { decoder(); }

    bool is_cf();
    bool is_zf();
    void trans2protect();

    uint8_t get_code8();
    uint16_t get_code16();
    uint32_t get_code32();

    void show_registers();
    void show_segment_registers();
    void show_memory() { memory.show_memory(); }

    void decoder();
};

inline bool CPU::is_cf()
{
  if ((eflags & 0x80000000) >> 31 == 1)
    return true;
  else 
    return false;
}

inline bool CPU::is_zf()
{
  if ((eflags & 0x02000000) >> 25 == 1)
    return true;
  else 
    return false;
}

inline uint8_t CPU::get_code8()
{
  uint8_t code = memory.read_8(eip);
  return code;
}

inline uint16_t CPU::get_code16()
{
  uint16_t code = memory.read_16(eip);
  return code;
}

inline uint32_t CPU::get_code32()
{
  uint32_t code = memory.read_32(eip);
  return code;
}
