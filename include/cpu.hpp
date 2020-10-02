#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>
#include "hardware.hpp"

enum Cpu_Attributes{CORES=2, FREQUENCY= 3, PROGRAM=4};


class Cpu : public HardWare, public HardWareLabeled{
  private:
    unsigned int _cores;
    unsigned int _freq;
    std::string _program;
  public:
    static unsigned int _pc;
    Cpu(std::string path);
    void infos();
    bool finished();
    bool isEmpty();
    void reset();
    void compute();
    void simulate();
    void read();
};

#endif
