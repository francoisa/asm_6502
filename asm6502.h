#ifndef ASM6502_H
#define ASM6502_H
#include "assembler.h"
#include <unordered_map>
#include <map>
#include <vector>


enum class Mode {ABSOLUTE,  ABSOLUTE_X,  ABSOLUTE_Y,  ACCUMULATOR,  IMMEDIATE,  
    IMPLIED,  INDIRECT,  INDIRECT_X,  INDIRECT_Y,  PC_2,  RELATIVE,  ZEROPAGE,  
    ZEROPAGE_X,  ZEROPAGE_Y};

class Asm6502Instruction {
public:
  Asm6502Instruction() = default;
  Asm6502Instruction(unsigned o, Mode m, int b) : opcode(o), mode(m), bytes(b) {}
  void convert(const std::string& args, std::vector<int>& byte_vec) const;
private:
  unsigned opcode;
  Mode mode;
  int bytes;
};

struct Instructions {
  std::map<Mode, Asm6502Instruction> opcode_map;
};

class Asm6502 : public Assembler {
public:
  Asm6502();
  Asm6502(const Asm6502&) = default;
  Asm6502& operator=(const Asm6502&) = default;
  Asm6502(Asm6502&&) = default;
  Asm6502& operator=(Asm6502&&) = default;
  void process(const std::string& in, std::ostream& out, Format fmt) const;
private:
  Mode determine_mode(const std::string& args) const;
  const Asm6502Instruction& opcode(const std::string& symbol, 
				   const std::string& args) const;
  std::unordered_map<std::string, Instructions> symbol_map;
  void parse_instruction(const std::string& line);
};

#endif
