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
    std::string _label;
    std::string _type;

  public:
    HardWare* _source;
    static bool binded; //pour savoir quand tout est bindé
    virtual void infos() const=0;
    virtual void simulate()=0;
    virtual std::pair<bool, double> read()=0;
    

};

class Component : public HardWare{
  protected:
    std::string _sourceLabel;

  public:
    virtual void infos() const=0;
    virtual void simulate()=0;
    virtual std::pair<bool, double> read()=0;
    virtual void tellLabelSource() const=0;
    //void bind();

};


void deleteSpace(std::string& str);

#endif
