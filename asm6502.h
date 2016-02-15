#ifndef ASM6502_H
#define ASM6502_H
#include "assembler.h"

class Asm6502 : public Assembler {
public:
  Asm6502() = default;
  Asm6502(const Asm6502&) = default;
  Asm6502& operator=(const Asm6502&) = default;
  Asm6502(Asm6502&&) = default;
  Asm6502& operator=(Asm6502&&) = default;
  int opcode(const std::string& instruction) const;
  void process(const std::string& in, std::ostream& out, Format fmt) const;
};

#endif
