#ifndef MEM_H
#define MEM_H

#include <iostream>
#include <string>
#include "hardware.hpp"


class Memory : public Component, public HardWareLabeled{
  private:
    unsigned int _size;
    unsigned int _access;
  public:
    static unsigned int _accesCt;
    Memory(std::string path);
    void bind();
    void simulate();
    void read();
};

#endif
