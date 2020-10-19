#include <stdint.h>
extern void io_hlt(void);
extern uint8_t io_in8(uint16_t port);
extern void io_out8(uint16_t port, uint8_t data);

#define COL8_000000		0
#define COL8_FF0000		1
#define COL8_00FF00		2
#define COL8_FFFF00		3
#define COL8_0000FF		4
#define COL8_FF00FF		5
#define COL8_00FFFF		6
#define COL8_FFFFFF		7
#define COL8_C6C6C6		8
#define COL8_840000		9
#define COL8_008400		10
#define COL8_848400		11
#define COL8_000084		12
#define COL8_840084		13
#define COL8_008484		14
#define COL8_848484		15

void boxfill(unsigned int color_code, int x0, int y0, int x1, int y1)
{
  unsigned char *vram = (unsigned char *) 0xa0000;
  for (int x = x0; x <= x1; x++) {
    for (int y = y0; y <= y1; y++) {
      vram[x + 320 * y] = color_code;
    }
  }
}

void init_screen() 
{
  int xsize = 320, ysize = 200;

  boxfill(COL8_008484,	0, 			0, xsize - 1, ysize - 29);
  boxfill(COL8_C6C6C6, 	0, ysize - 28, xsize - 1, ysize - 28);
  boxfill(COL8_FFFFFF, 	0, ysize - 27, xsize - 1, ysize - 27);
  boxfill(COL8_C6C6C6, 	0, ysize - 26, xsize - 1, ysize - 1);

  boxfill(COL8_FFFFFF, 	3, ysize - 24, 59, ysize - 24);
  boxfill(COL8_FFFFFF, 	2, ysize - 24, 2, ysize - 4);
  boxfill(COL8_848484, 	3,	ysize - 4, 59, ysize - 4);
  boxfill(COL8_848484,59,	ysize - 23, 59, ysize - 5);
  boxfill(COL8_000000, 	2, ysize - 3, 59, ysize - 3);
  boxfill(COL8_000000, 	60, ysize -24, 60, ysize -3);

  boxfill(COL8_848484, xsize - 47, ysize - 24, xsize - 4, ysize - 24);
  boxfill(COL8_848484, xsize -47, ysize - 23, xsize - 47, ysize - 4);
  boxfill(COL8_FFFFFF, xsize - 47, ysize - 3, xsize - 4, ysize - 3);
  boxfill(COL8_FFFFFF, xsize - 3, ysize - 24, xsize - 3, ysize - 3);
}	

#define PORT 0x3F8
void init_serial()
{
  io_out8(PORT + 1, 0x00);
  io_out8(PORT + 2, 0xc7);
}

int serial_recv()
{
  return io_in8(PORT + 5) & 1;
}

uint8_t serial_read()
{
  while (serial_recv() == 0);
  return io_in8(PORT);
}

int is_transmit_empty()
{
  return io_in8(PORT + 5) & 0x20;
}

void serial_write(uint8_t data)
{
  while(is_transmit_empty() == 0);

  io_out8(PORT, data);
}
