#ifndef TAPE
#define TAPE

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Tape {
  public: 
    Tape(std::string filename);
    virtual ~Tape() = default;
    void clear();
    void show();
    std::string getFileName();
  protected:
    std::vector<int> values_;
    int index_;
    std::string fileName_;
};

#endif