#pragma once
#include "memory.h"
#include "register.h"

#include <vector>

#define DEFAULT_START_UP_ADDRESS 0x7c00

class ModRM;


class CPU {
  public:
    Memory memory;
    Register registers[8];
    enum registers {EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI, REGISTER_COUNT};
    Register eip;

    CPU();
    CPU(uint8_t data[], uint32_t size, uint32_t addr = DEFAULT_START_UP_ADDRESS);
    ~CPU();

    void run() { decoder(); }

    uint8_t get_code8();
    uint32_t get_code32();

    void show_registers();
    void show_memory() { memory.show_memory(); }

    void decoder();

    void set_rm32(ModRM &modrm, uint32_t val);
    uint32_t get_r32(ModRM &modrm);
};
