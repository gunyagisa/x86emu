#pragma once
#include <bits/stdint-uintn.h>
#include <string>
#include <iostream>

class Register {
private:
  std::uint32_t reg;

public:
  Register();
  Register(uint32_t init);
  Register(const Register &src);

  void setname(std::string name) { name = name; }

  operator uint32_t() { return reg; }

  void write_8h(uint8_t val);
  void write_8l(uint8_t val);
  void write_16(uint16_t val);
  void write_32(uint32_t val);


  uint8_t read_8h(void);
  uint8_t read_8l(void);
  uint16_t read_16(void);
  uint32_t read_32(void);

  friend std::ostream &operator<<(std::ostream &, const Register &);

  Register& operator++();
  Register operator++(int);
  Register& operator+=(const Register& rhs) { reg += rhs.reg; return *this; }
};
