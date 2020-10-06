#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include "hardware.hpp"
#include "mem.hpp"

enum Display_Attributes{REFRESH=1, SOURCE=2};

class Display{
  private:
    unsigned int _refresh;
    std::string _type;
    std::string _sourceLabel;

  public:
    HardWare* _source;
    Display(std::string path);
    void infos() const;
    std::string tellLabelSource() const;
    std::string tellLabel() const;
    void bind(HardWare* source);
    void simulate();
};

#endif
