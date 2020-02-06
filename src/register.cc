#include "register.h"

Register::Register() : reg(0), name("no name") {}
Register::Register(std::string name) : reg(0), name(name)
{}

std::ostream& operator << (std::ostream& stream, const Register &Register)
{
    stream << Register.name << ":";
    stream << std::showbase << std::hex << Register.reg;
    return stream;
};
