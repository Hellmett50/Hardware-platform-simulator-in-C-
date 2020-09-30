#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include "hardware.hpp"


class Display : public Component{
  private:
    unsigned int _refresh;
  public:
    static unsigned int _resfreshCt;
    Display(std::string path);
    void bind();
    void simulate();
};

#endif
