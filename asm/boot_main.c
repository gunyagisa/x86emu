extern void init_serial();
extern void serial_write(char a);

int main()
{
  init_serial();
  serial_write('A');
}
