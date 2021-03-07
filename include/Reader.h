#ifndef READER
#define READER

#define COMMENT_SYMBOL_1 ';'
#define COMMENT_SYMBOL_2 '#'

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <regex>
#include <map>
#include <algorithm>
#include "./instructions/ADD.h"
#include "./instructions/DIV.h"
#include "./instructions/LOAD.h"
#include "./instructions/MULT.h"
#include "./instructions/READ.h"
#include "./instructions/STORE.h"
#include "./instructions/SUB.h"
#include "./instructions/WRITE.h"
#include "./instructions/JUMP.h"
#include "./instructions/JGTZ.h"
#include "./instructions/JZERO.h"

enum Opcodes {LOAD, STORE, ADD, SUB, MULT, DIV, READ, WRITE};

class Reader {
  private:
    std::vector<std::shared_ptr<Instruction>> instructions_;
    std::vector<std::string> normalOpcodes;  
    std::vector<std::string> jumpOpcodes;
    std::string FileName_;
    std::string fileText_;
  public:
    Reader(std::string);
    ~Reader();
    std::vector<std::shared_ptr<Instruction>> parseText();
    Instruction* getInstruction(int line);
    void reset(std::string);
    int isNormal(std::string);
    int isJump(std::string);
    void print();
    int getLineByTag();
    std::string getFileName();
  private:
    void load(std::string);
    void SetTags(std::string);
    std::string readFile(std::string);
    void parseInstructions(std::string);
};

#endif