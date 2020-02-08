#pragma once
#include "memory.h"
#include "register.h"

#include <vector>


class CPU {
  private:
    Memory memory;
    Register registers[8];
    enum registers {EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI, REGISTER_COUNT};
    Register eip;

  public:
    CPU();
    CPU(uint8_t data[], uint32_t size, uint32_t addr = 0);
    ~CPU();

    void run() { decoder(); }

    void show_registers();
    void show_memory() { memory.show_memory(); }

    void decoder();

    void mov_r32_imm32(uint8_t reg, uint32_t num);
};
