#include <bits/stdint-uintn.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

class FIFO {
  private:
    uint8_t *fifo;
    uint32_t size;
    uint32_t sp;
    bool status;

  public:
    FIFO(uint32_t size=256)
      :size(size), sp(0), status(false)
    {
      fifo = new uint8_t[size];
    }

    ~FIFO()
    {
      delete fifo;
    }

    void push(uint8_t data)
    {
      if (sp >= size) {
        fprintf(stderr, "FIFO size overflow!\n");
        exit(1);
      }
      fifo[sp++] = data;
    }

    uint8_t pop()
    {
      if (sp <= 0) {
        fprintf(stderr, "FIFO crashed!\n");
        exit(1);
      }
      return fifo[--sp];
    }

    inline void enable() { status = true; }
    inline void disable() { status = false; }

};

struct SERIAL {
  uint8_t status;
  uint8_t interrupt;
  FIFO fifo;
};
