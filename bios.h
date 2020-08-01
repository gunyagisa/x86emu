#pragma once

#include "cpu.h"

void software_interrupt(CPU &cpu);

// vector = 0x13
int disk_service(uint8_t);
