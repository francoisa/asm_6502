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
  virtual void process(const std::string& line, 
		       std::ostream& out, Format fmt) const = 0;
};

#endif
