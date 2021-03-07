#ifndef INSTRUCTION
#define INSTRUCTION

#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <algorithm>
#include <map>
#include "./Memory.h"
#include "./OutputTape.h"
#include "./InputTape.h"

class Instruction {
  protected:
    std::string operator_;
    std::string operand_;
    std::string tag_;
    char type_;
    int line_;
    virtual void parseInstruction(std::string instructionText) = 0;
  public:
    Instruction(std::string tag, int line);
    virtual ~Instruction() = default;
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc) = 0;
    std::string getOperator();
    std::string getOperand();
    std::string getTag();
    char getType();
    int getLine();
    void printInstruction();
};

#endif