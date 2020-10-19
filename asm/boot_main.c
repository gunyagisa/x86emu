#include "boot_main.h"

int main()
{
  init_serial();
  serial_write('A');
}
