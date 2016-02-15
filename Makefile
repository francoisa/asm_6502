TGT = asm_6502
OBJS := $(patsubst %.cc,.obj/%.o,$(wildcard *.cc))
CXX = g++
CC = g++
DEBUG = -g
CXXFLAGS = -Wall -std=c++0x $(DEBUG)

$(TGT): $(OBJS)
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

.obj/%.o: %.cc
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

main.o: main.cc  asm6502.h

asm6502.o: asm6502.cc asm6502.h assembler.h

clean:
	rm -f .obj/*.o *~ $(TGT)
