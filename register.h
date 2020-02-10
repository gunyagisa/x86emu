#pragma once
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

  friend std::ostream &operator<<(std::ostream &, const Register &);

  Register& operator++();
  Register operator++(int);
  Register& operator+=(const Register& rhs) { reg += rhs.reg; return *this; }
  operator int() { return reg; }
  
};
