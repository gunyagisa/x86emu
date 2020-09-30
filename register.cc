#include "register.h"
#include <iomanip>

Register::Register() : reg(0) {}
Register::Register(uint32_t init) : reg(init) {}
Register::Register(const Register& src) : reg(src.reg) {}


std::ostream& operator << (std::ostream& stream, const Register &Register)
{
    stream << "0x" << std::hex << std::setw(8) << Register.reg << std::setfill('0');
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
