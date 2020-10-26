#ifndef HW_H
#define HW_H

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <iterator>
#include <fstream>
#include <cstddef>
#include <exception>
#include "notify.hpp"

enum Attributes{TYPE=0, LABEL=1};

class HardWare{
  protected:
    std::string _label;
    std::string _type;

  public:
    HardWare* _source;
    std::string _sourceLabel;
    static bool binded; //pour savoir quand tout est bindé
    virtual void infos() const=0;
    virtual void simulate()=0;
    virtual std::pair<bool, double> read()=0;
    std::string tellLabel() const;
    virtual std::string tellLabelSource() const;
    void bind(HardWare* source);

};

void deleteSpace(std::string& str);

#endif
