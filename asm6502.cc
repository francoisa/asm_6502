#include "asm6502.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <exception>

using namespace std;
static std::map<std::string, Mode> mode_map = {
  {"absolute", Mode::ABSOLUTE},  
  {"absolute,X", Mode::ABSOLUTE_X},  
  {"absolute,Y", Mode::ABSOLUTE_Y},  
  {"accumulator", Mode::ACCUMULATOR},  
  {"immediate", Mode::IMMEDIATE},  
  {"implied", Mode::IMPLIED},  
  {"indirect", Mode::INDIRECT},  
  {"(indirect,X)", Mode::INDIRECT_X},  
  {"(indirect),Y", Mode::INDIRECT_Y},  
  {"(PC+2)", Mode::PC_2},  
  {"relative", Mode::RELATIVE},  
  {"zeropage", Mode::ZEROPAGE},  
  {"zeropage,X", Mode::ZEROPAGE_X},  
  {"zeropage,Y", Mode::ZEROPAGE_Y}};

static std::vector<std::string> args = { "A", "(oper)", "#oper", "oper", "(oper,X)", 
				  "oper,X", "(oper),Y", "oper,Y" };

class bad_opcode : public std::exception {
public:
  const char* what() const throw() {
    return "Bad opcode";
  }
} bad_opcode_exception;

void Asm6502Instruction::convert(const std::string& args, 
				 std::vector<unsigned>& byte_vec) const {
  
}

Asm6502::Asm6502() {
  std::ifstream ifs("asm6502.dat");
  std::string line;
  while (getline(ifs, line)) {
    std::istringstream iss(line);
    parse_instruction(line);
  }
}

Asm6502Instruction Asm6502::get_instruction(const std::string& symbol, Mode mode) const {
  return symbol_map.find(symbol)->second.opcode_map.find(mode)->second;
}

void Asm6502::parse_instruction(const std::string& line) {
  std::istringstream iss(line);
  std::string field;
  std::vector<std::string> fields;
  while (iss >> field) {
    fields.push_back(field);
  }
  const std::string& mode = fields[0];
  const std::string& symbol = fields[1];
  int offset = fields.size() == 6 ? 1 : 0;
  const std::string& opcode = fields[2+offset];
  unsigned opcode_byte;
  std::istringstream iss1(opcode);
  if (iss1 >> std::hex >> opcode_byte) {
    const std::string& bytes_str = fields[3+offset];
    std::istringstream iss2(bytes_str);
    int bytes = 1;
    iss2 >> bytes;
    Instructions& instructions = symbol_map[symbol];
    Asm6502Instruction asm6502_instruction(opcode_byte, mode_map[mode], bytes);
    instructions.opcode_map[mode_map[mode]] = asm6502_instruction; 
  }
  else {
    std::cerr << "Could not convert opcode '" << opcode << "' to unsigned." 
	      << std::endl;
  }
}

Mode Asm6502::determine_mode(const std::string& args) const {
  Mode mode = Mode::IMMEDIATE;
  return mode;
}

const Asm6502Instruction& Asm6502::opcode(const string& symbol, const std::string& args) const {
  Mode mode = determine_mode(args);
  auto instr = symbol_map.find(symbol);
  if (instr != symbol_map.end()) {
    std::cerr << "Error: symbol '" << symbol << "' not found." << std::endl;
    throw bad_opcode_exception;
  }
  else { 
    return instr->second.opcode_map.find(mode)->second;
  }
}

void Asm6502::process(const string& line, ostream& out, Format fmt) const { 
  std::istringstream iss(line);
  std::string field;
  std::vector<std::string> fields;
  while (iss >> field) {
    fields.push_back(field);
  }
}
