#ifndef MEMORY
#define MEMORY

#include <string>
#include <vector>

class Memory {
  private:
    std::vector<int> registers_;
    int* acc_;
    int size_;
  public:
    Memory();
    ~Memory();
    int getRegister(int registerNumber);
    void setRegister(int registerNumber, int value);
    int getAcc();
    void setAcc(int value);
};

#endif