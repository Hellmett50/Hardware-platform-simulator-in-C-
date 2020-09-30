#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>
#include "hardware.hpp"


class Cpu : public HardWare{
  private:
    unsigned int _cores;
    unsigned int _freq;
    std::string _program;
  public:
    static unsigned int _pc;
    Cpu(std::string path);
    bool finished();
    bool isEmpty();
    void reset();
    void compute();
    void simulate();
    void read();
};

#endif
