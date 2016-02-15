#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>

enum class Format { TEXT, BINARY };

class  Assembler {
public:
  Assembler() = default;
  Assembler(const Assembler&) = delete;
  Assembler& operator=(const Assembler&&) = delete;
  Assembler(Assembler&&) = delete;
  Assembler& operator=(Assembler&&) = delete;
  virtual  ~Assembler() {}
  virtual int opcode(const std::string& instruction) const = 0;
  virtual void process(const std::string& in, std::ostream& out, Format fmt) const = 0;
};

#endif
