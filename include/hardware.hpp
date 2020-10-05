#ifndef HW_H
#define HW_H

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
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
    virtual void infos() const=0;
    virtual void simulate()=0;

};

class HardWareLabeled{
  protected:
    std::string _label;
  public:
    std::map<bool, double> read() const;

};

class Component : public HardWare{
  protected:
    std::string _source;

  public:
    virtual void infos() const=0;
    virtual void simulate()=0;
    void tellLabelSource() const;
    void bind();

};

void deleteSpace(std::string& str);

#endif
