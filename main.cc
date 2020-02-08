#include "cpu.h"
#include <iostream> 
#include <vector>
#include <bitset>

int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cout << "few argument\n";
    exit(1);
  }

  FILE *fp;
  fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    perror("[E] :fopen");
    exit(1);
  }

  fclose(fp);
  CPU cpu;

}

