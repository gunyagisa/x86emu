#include "register.h"

Register::Register() : reg(0) {}
Register::Register(uint32_t init) : reg(init) {}
Register::Register(const Register& src) : reg(src.reg) {}

std::ostream& operator << (std::ostream& stream, const Register &Register)
{
    stream << std::showbase << std::hex << Register.reg;
    return stream;
}

Register& Register::operator++()
{
  ++reg;
  return *this;
}
Register Register::operator++(int)
{
  Register tmp{*this};
  ++reg;
  return tmp;
}
