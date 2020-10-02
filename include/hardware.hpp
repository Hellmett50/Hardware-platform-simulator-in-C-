#ifndef HW_H
#define HW_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <cstddef>
#include <exception>

enum Attributes{TYPE=0, LABEL=1};

class HardWare{
  protected:
    std::map<bool, double> _dataValue;
    std::string _type;

  public:
    static bool binded; //pour savoir quand tout est bindé
    void infos();

};

class HardWareLabeled{
  protected:
    std::string _label;
  public:

};

class Component : public HardWare{
  protected:
    std::string _source;

  public:
    void tellLabelSource();

};

#endif
