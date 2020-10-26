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
    double read();
    void write(double value);

};//End of class Register

class Cpu : public HardWare{

  private:
    unsigned int _cores;
    unsigned int _freq;
    Program _prog;
    Register _reg;
    std::string tellLabelSource();

  public:
    Cpu(/*std::string path*/);
    int load(std::string path);
    void infos() const;
    void simulate();
    std::pair<bool, double> read();
    int add(){return 4;}

};//End of class Cpu

#endif
