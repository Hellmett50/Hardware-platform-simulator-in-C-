#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <string>
#include "hardware.hpp"
#include "cpu.hpp"

class Bus : public Component, public HardWareLabeled{
  private:
    unsigned int _width;
    std::queue<std::pair<bool, double>> _pendingValues;
    std::queue<std::pair<bool, double>> _readyValues;
  public:
    Cpu* _cpu;
    static unsigned int _readCt;
    void tellLabelSource() const;
    Bus(std::string path);
    void infos() const;
    void bind();
    void simulate();
    std::pair<bool, double> read();
};

#endif
