#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>
#include "hardware.hpp"

enum Cpu_Attributes{CORES=2, FREQUENCY= 3, PROGRAM=4};

class Instruction{

  private:
    std::string _opCode;
    double _op1, _op2;
  public:
    double compute() const;
    void getInstruction(std::string opCode, double op1, double op2);
    void printInstruction() const;

};//End of class Instruction

class Program{

  private:
    std::string _path;
    std::vector<Instruction> _inst;
    unsigned int _pc;
    double _result;
  public:
    Program();
    void loadProgram(std::string path);
    double compute();
    bool finished() const;
    void printInstruction() const;
    void printPath() const;
    void reset();

};//End of class Program

class Register{

  private:
    std::queue<double> _value;
  public:
    bool isEmpty() const;
    double read() const;
    void write(double value);

};//End of class Register

class Cpu : public HardWare, public HardWareLabeled{

  private:
    unsigned int _cores;
    unsigned int _freq;
    std::string _program;
    Program _prog;
    Register _reg;
  public:
    static unsigned int _pc;
    Cpu(std::string path);
    void infos();
    bool finished();
    bool isEmpty();
    void infos() const;
    void reset();
    void compute();
    void simulate();
    void read();
};
    std::map<bool, double> read() const;

};//End of class Cpu

#endif
