#include "gtest/gtest.h"
#include <asm6502.h>

TEST(asm6502_test, ctor) {
  Asm6502 asm6502;
  const Asm6502Instruction& instr = asm6502.get_instruction("ADC", Mode::ABSOLUTE);
  const unsigned ADC(0x01); 
  EXPECT_EQ (ADC, instr.opcode());
  EXPECT_EQ (Mode::ABSOLUTE, instr.mode());
  EXPECT_EQ (3, instr.bytes());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
