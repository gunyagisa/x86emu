#pragma once

#include "cpu.h"
#include <bits/stdint-uintn.h>


// for cpu configuration
bool is_segment(CPU &cpu);
bool is_paging(CPU &cpu);
void set_protected_mode(CPU &cpu);
void set_manager(CPU &cpu, const char *file);

// for memory
uint32_t get_real_addr(uint32_t addr, CPU &cpu);


void load_ipl(unsigned char *buf, const char *file);
