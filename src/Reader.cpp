#include "../include/Reader.h"

//Constructor de la clase Reader, lee un fichero y lo almacena en un string
Reader::Reader(std::string fileName) {
  instructions_.resize(0);
  FileName_ = fileName;
  normalOpcodes = {"LOAD", "STORE", "ADD", "SUB", "MULT", "DIV", "READ", "WRITE"};
  jumpOpcodes = {"JUMP", "JGTZ", "JZERO"};
  std::ifstream file(fileName);
  std::string inputStr;
  std::string regexStr = COMMENT_SYMBOL_1 + ".*";
  std::regex isComment(regexStr);
  if (!file.is_open()) {
    std::cout << "No se pudo abrir el fichero\n";
  } else {
    while (std::getline(file,inputStr)) {
      std::transform(inputStr.begin(),inputStr.end(),inputStr.begin(),::toupper);
      if (std::regex_match(inputStr,isComment)) {
        inputStr = std::regex_replace(inputStr,isComment,"");
      }
      fileText_ += inputStr + "\n";
    }
  }
}

//Destructor de la clase Reader
Reader::~Reader() {}

//Analiza gramaticalmente el programa y crea las instrucciones correspondientes
std::vector<std::shared_ptr<Instruction>> Reader::parseText() {
  std::istringstream program(fileText_);
  std::string analyzedString;
  std::string token;
  std::regex isNumber("([0-9]+)|(-[0-9]+)");
  std::regex isTag(".*:");
  int line = 1;
  int opcode;
  while (getline(program,analyzedString)) {
    std::shared_ptr<Instruction> ptr;
    std::string operat;
    std::string operand;
    std::string tag;
    char type;
    std::istringstream lineOfText(analyzedString);
    lineOfText >> token;
    std::smatch match;
    if (token == "") {
      line++;
      continue;
    }
    if (std::regex_search(token, match, isTag)) {
      tag = match[0];
      lineOfText >> token;
      analyzedString.erase(analyzedString.begin(), analyzedString.begin() + tag.length());
    }
    if (token == "HALT") {
      operat = "HALT";
    }
   opcode = isJump(token);
    if (opcode != -1) {
      if (opcode == 0) {
        JUMPInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<JUMPInstruction>(objInstruction);
      }
      if (opcode == 1) {
        JGTZInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<JGTZInstruction>(objInstruction);
      }
      if (opcode == 2) {
        JZEROInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<JZEROInstruction>(objInstruction);
      }
      ptr->printInstruction();
      instructions_.push_back(ptr);
    }
    opcode = isNormal(token);
    if (opcode != -1 ) {
      if(opcode == 0) {
        LOADInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<LOADInstruction>(objInstruction);
      } else if (opcode == 1) {
        STOREInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<STOREInstruction>(objInstruction);
      }else if (opcode == 2) {
        ADDInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<ADDInstruction>(objInstruction);
      } else if (opcode == 3) {
        SUBInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<SUBInstruction>(objInstruction);
      } else if (opcode == 4) {
        MULTInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<MULTInstruction>(objInstruction);
      } else if (opcode == 5) {
        DIVInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<DIVInstruction>(objInstruction);
      } else if (opcode == 6) {
        READInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<READInstruction>(objInstruction);
      } else if (opcode == 7) {
        WRITEInstruction objInstruction(analyzedString, tag, line);
        ptr = std::make_shared<WRITEInstruction>(objInstruction);
    }
      ptr->printInstruction();
      instructions_.push_back(ptr);
    }
    line++;
  }
  return instructions_;
}

//Funcion que comprueba si es una instruccion de tipo jump
int Reader::isJump(std::string token) {
  for (int i = 0; i < jumpOpcodes.size(); i++) {
    if (jumpOpcodes[i] == token)
      return i;
  }
  return -1;
}

//Funcion que comprueba si es una instruccion de tipo normal
int Reader::isNormal(std::string token) {
  for (int i = 0; i < normalOpcodes.size(); i++) {
    if (normalOpcodes[i] == token)
      return i;
  }
  return -1;
}
