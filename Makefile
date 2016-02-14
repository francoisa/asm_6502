TGT = asm_6502
OBJS = .obj/*.o
CXX = g++
CC = g++
DEBUG = -g
CXXFLAGS = -Wall -std=c++0x -c $(DEBUG)
LDFLAGS = -Wall -lstdc++ $(DEBUG)

.obj/%.o: %.cc
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

$(TGT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TGT)

main.o:  main.cc

clean:
	rm -f .obj/*.o *~ $(TGT)
