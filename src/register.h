#pragma once
#include <string>
#include <iostream>

class Register {
private:
  std::string name;
  std::uint32_t reg;

public:
  Register();
  Register(std::string);

  void setname(std::string name) { name = name; }

  friend std::ostream &operator<<(std::ostream &, const Register &);
};
