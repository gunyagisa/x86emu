#include "memory.h"
#include "register.h"

#include <vector>

class CPU {
  private:
    Memory memory;
    Register registers[8];
    std::vector<std::string> registers_name = 
    {
      "EAX", "ECX", "EDX", "EBX", "ESP", "EBP", "ESI", "EDI"
    };
    Register eip;

  public:
    CPU();
    ~CPU();
};
