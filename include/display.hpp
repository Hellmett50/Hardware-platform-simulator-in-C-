#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include "hardware.hpp"
#include "mem.hpp"

enum Display_Attributes{REFRESH=1, SOURCE=2};

class Display : public Component{
  private:
    unsigned int _refresh;
  public:
    Display(std::string path);
    void infos() const;
    void tellLabelSource() const;
    void bind();
    void simulate(/*Memory mem*/);
};

#endif
