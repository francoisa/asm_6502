#include <iostream>
#include <fstream>
#include "asm6502.h"

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
    std::cout << "Enter an assembly file: ";
    while (std::cin >> asm_file) {
      process(asm_file, std::cout, Format::TEXT);
      std::cout << "Enter a assembly file: ";
    }
    return 0;
  }
}
