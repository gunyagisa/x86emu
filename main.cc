#include "cpu.h"
#include "bios.h"
#include <bits/stdint-uintn.h>
#include <iostream> 
#include <sstream>
#include <vector>
#include <bitset>
#include <cstdio>
#include <thread>

#include "gui.cc"

void set_protected_mode(CPU &cpu)
{
  cpu.mode = PROTECTED_MODE;
}

void set_manager(CPU &cpu, char *file)
{
  cpu.manager.disk_name = file;
}

void load_ipl(unsigned char *buf, char *file)
{
  FILE *fp;

  fp = fopen(file, "rb");

  if (fp == NULL) {
    perror(__FUNCTION__);
    exit(1);
  }

  fread(buf, sizeof(uint8_t), 512, fp);
  fclose(fp);
}

void Thread1(CPU &cpu, int *argc, char **argv)
{
  gui.Init(320, 200, cpu.memory + 0xa0000);
  start(gui, argc, argv);
}

void Thread2(CPU &cpu)
{
  printf("start emulator\n");
  cpu.run();

  while(1) {
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cout << "few argument\n";
    exit(1);
  }

  printf("load ipl\n");
  unsigned char buf[512];
  load_ipl(buf, argv[1]);

  CPU cpu{buf, 512, 0x7c00};
  set_manager(cpu, argv[1]);

  // gpu thread
  std::thread th1(Thread1, std::ref(cpu), &argc, argv);
  th1.detach();
  // emulation thread
  std::thread th2(Thread2, std::ref(cpu));
  th2.join();

  printf("finish\n");
}
