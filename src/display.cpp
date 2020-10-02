#include "../include/display.hpp"

using namespace std;

Display::Display(string path){

  cout << "\n\n==================\n"
       << "Loading component DISPLAY...\n" << endl;

  int ct_attribute=0;
  ifstream stream;
  string attribute;

  stream.open(path);

  if(!stream.is_open()){
    throw "Failed to open file : "+path;
  }

  while(getline(stream, attribute)!=0){

    size_t found = attribute.rfind(": ");
    if (found!=string::npos)
      attribute.erase(0,found+2);

    switch (ct_attribute) {
      case TYPE:
        _type=attribute;
      break;
      case REFRESH:
        _refresh=stoi(attribute);
      break;
      case SOURCE:
        _source=attribute;
      break;
    }
    ct_attribute++;
  }

  infos();
  cout << "DISPLAY loaded !" << endl;
  cout << "==================" << "\n"<< endl;

  stream.close();

}

void Display::infos(){

  cout << "TYPE: " << _type << '\n'
       << "REFRESH: " << _refresh << '\n'
       << "SOURCE: " << _source << '\n' << endl;

}
