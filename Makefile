TGT = asm6502
TST = test/$(TGT).t
OBJS =$(patsubst %.cc,.obj/%.o,$(wildcard *.cc))
CXX =clang++-3.5
CC =clang-3.5
DEBUG =-g
GTEST =../googletest/
CXXFLAGS = -Wall -std=c++11 -I. -I$(GTEST)/include $(DEBUG)
TESTLIBS = -L$(GTEST) -lgtest

$(TGT): $(OBJS)
	$(LINK.cc) $^ $(LOADLIBS) $(LDLIBS) -o $@

$(TST): .obj/asm6502.o test/.obj/asm6502.t.o
	$(LINK.cc) $^ $(LOADLIBS) $(TESTLIBS) -o $@

.obj:
	mkdir .obj

.obj/%.o: %.cc .obj
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

test/.obj/%.o: test/%.cc
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

main.o: main.cc asm6502.h

asm6502.o: asm6502.cc asm6502.h assembler.h

asm6502.t.o: asm6502.t.cc asm6502.cc asm6502.h assembler.h

clean:
	rm -f .obj/*.o *~ $(TGT) test/.obj/*.o $(TST)

test: .obj/asm6502.o test/.obj/asm6502.t.o $(TST)
	$(TST)
