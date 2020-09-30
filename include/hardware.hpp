#ifndef HW_H
#define HW_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>

class HardWare{
  protected:
    std::string _label;
    std::string _type;

  public:

};

class Component : public HardWare{
  protected:
    std::string _source;

  public:
    void tellLabelSource();

};

#endif
