#ifndef ITAPE
#define ITAPE

#include "Tape.h"
#include <string>
#include <regex>

class InputTape : public Tape {
  public: 
    InputTape(std::string fileName);
    virtual ~InputTape();
    void load(std::string fileName);
    void reset(std::string);
    void reset();
    int getIndex();
    int getElement();
    int read();
    bool notEnd();
    void printInputTape();
};

#endif