#include "../include/hardware.hpp"

using namespace std;

/*============HardWare============*/
string HardWare::tellLabel() const{
  return _label;
}

string HardWare::tellLabelSource() const{
  return _sourceLabel;
}

unsigned int HardWare::tellPriority() const{
  return _priority;
}

void HardWare::bind(HardWare* source) {
  _source = source;
}//End of HardWare::bind()

/*============Functions============*/
void deleteSpace(string& str){

  string::iterator i = str.begin();

  for(auto a : str){
    if(a==' ')
      i+=1;
    else
      break;
  }
  str.erase(remove(str.begin(),i, ' '), i);

}
