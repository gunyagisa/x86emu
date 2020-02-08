#include "memory.h"

Memory::Memory() : size(1024)
{
    memory = new uint8_t[size];
}

Memory::Memory(uint32_t size) : size(size)
{
    memory = new uint8_t[size];
}

Memory::~Memory()
{
    delete memory;
}

void Memory::write_8(uint8_t data, uint32_t addr)
{
    memory[addr] = data;
}

uint8_t Memory::read_8(uint32_t addr)
{
    return memory[addr];
}

