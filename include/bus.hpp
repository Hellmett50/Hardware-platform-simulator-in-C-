#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <string>
#include "hardware.hpp"


class Bus : public Component, public HardWareLabeled{
  private:
    unsigned int _width;
  public:
    static unsigned int _readCt;
    Bus(std::string path);
    void bind();
    void simulate();
    void read();
};

#endif
