extern void init_serial();
extern void serial_write(char a);
extern void io_hlt();

int main()
{
  init_serial();
  serial_write('A');

  io_hlt();
}
