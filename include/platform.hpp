#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include <exception>

#include "hardware.hpp"
#include "mem.hpp"
#include "bus.hpp"
#include "cpu.hpp"
#include "display.hpp"

class Platform{

  private:

  public:
    std::vector<HardWare*> hardWareTemp;
    Display* display;
    size_t component_nb;
    Platform();
    int load(std::string platformName);
    void bind();
    void simulate();


};

#endif
