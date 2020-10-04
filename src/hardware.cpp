#include "../include/hardware.hpp"

using namespace std;

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
