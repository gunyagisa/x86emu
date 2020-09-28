#pragma once
#include "memory.h"
#include "register.h"

#include <vector>

#define DEFAULT_START_UP_ADDRESS 0x7c00

#define REAL_MODE 0
#define PROTECTED_MODE 1

class ModRM;


class CPU {
  public:
    struct manager {
      std::string disk_name;
    } manager;


    Memory memory; 
    Register registers[8];
    Register eip;
    Register cr[8];
    uint16_t cs, ds, es, ss, fs, gs;
    uint32_t eflags;

    enum registers {EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI, REGISTER_COUNT};

    struct  GDTR {
      uint16_t limit;
      uint32_t base;
    } gdtr;

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

    uint8_t get_code8();
    uint16_t get_code16();
    uint32_t get_code32();

    void show_registers();
    void show_segment_registers();
    void show_memory() { memory.show_memory(); }

    void decoder();
};
