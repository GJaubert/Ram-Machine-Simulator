CXX = g++
LDFLAGS =  -fsanitize=address

SRC = ./test/test.cpp ./src/InputTape.cpp ./src/OutputTape.cpp ./src/Reader.cpp ./src/RamMachine.cpp ./src/Tape.cpp ./src/Instruction.cpp ./src/Memory.cpp ./src/Instructions/ADD.cpp ./src/Instructions/DIV.cpp ./src/Instructions/JGTZ.cpp ./src/Instructions/JUMP.cpp ./src/Instructions/JZERO.cpp ./src/Instructions/LOAD.cpp ./src/Instructions/MULT.cpp ./src/Instructions/READ.cpp ./src/Instructions/STORE.cpp ./src/Instructions/SUB.cpp ./src/Instructions/WRITE.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = ./bin/execute

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)