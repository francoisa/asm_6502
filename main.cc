#include <iostream>
#include <fstream>


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


class Asm6502 : public Assembler {
public:
  Asm6502() = default;
  Asm6502(const Asm6502&) = default;
  Asm6502& operator=(const Asm6502&) = default;
  Asm6502(Asm6502&&) = default;
  Asm6502& operator=(Asm6502&&) = default;
  int opcode(const std::string& instruction) const { return 0; }
  void process(const std::string& in, std::ostream& out, Format fmt) const { }
};

void process(const std::string& src, std::ostream& out, Format fmt) {
  Asm6502 asm6502;
  std::ifstream ifs(src, std::ifstream::in);
  std::string line;
  while(getline(ifs, line)) {
    asm6502.process(line, out, fmt);
  }
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      process(argv[i], std::cout, Format::TEXT);
    }  
  }
  else {
    std::string asm_file;
    std::cout << "Enter a assembly file: ";
    while (std::cin >> asm_file) {
      process(asm_file, std::cout, Format::TEXT);
      std::cout << "Enter a assembly file: ";
    }
    return 0;
  }
}
