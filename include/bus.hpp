#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <string>
#include "hardware.hpp"

class Bus : public HardWare{
  private:
    unsigned int _width;
    std::queue<std::pair<bool, double>> _pendingValues;
    std::queue<std::pair<bool, double>> _readyValues;
  public:
    static unsigned int _readCt;
    Bus(std::string path);
    void infos() const;
    void bind();
    void simulate();
    std::pair<bool, double> read();
    //virtual std::string tellLabelSource() const;
};

#endif
