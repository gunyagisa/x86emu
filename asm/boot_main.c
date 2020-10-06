extern void io_hlt(void);

int main()
{
  for (int i = 0xa0000; i <= 0xaffff; i++) {
    *(int *) i = 0x07;
  }
  io_hlt();
}
