#include "../include/RamMachine.h"

int main(int argc, char* argv[]) {
    bool debugging = true;
    RamMachine machine("./ejemplosRAM/test0.ram", "./Tapes/input.tape", "./Tapes/output.tape", debugging);
    machine.compute();
  
  return 0;
}