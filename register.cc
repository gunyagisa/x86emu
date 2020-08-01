#include "register.h"
#include <iomanip>

Register::Register() : reg(0) {}
Register::Register(uint32_t init) : reg(init) {}
Register::Register(const Register& src) : reg(src.reg) {}

void Register::write_8h(uint8_t val)
{
  reg = (reg & 0xffff00ff) | (val << 8);
}

void Register::write_8l(uint8_t val)
{
  reg = (reg & 0xffffff00) | val;
}

void Register::write_16(uint16_t val)
{
  reg = (reg & 0xffff0000) | val;
}

void Register::write_32(uint32_t val)
{
  reg = val;
}

uint8_t Register::read_8h(void)
{
  return (reg & 0xff00) >> 8;
}

uint8_t Register::read_8l(void)
{
  return (reg & 0xff);
}

uint16_t Register::read_16(void)
{
  return (reg & 0xffff);
}

uint32_t Register::read_32(void)
{
  return reg;
}


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
