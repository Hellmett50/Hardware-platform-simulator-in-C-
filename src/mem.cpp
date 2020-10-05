#include "../include/mem.hpp"

using namespace std;

Memory::Memory(string path){

  cout << "Je suis une mémoire !!" << '\n';
  cout << path << endl;
  cout << "\n\n==================\n"
       << "Loading component MEMORY...\n" << endl;

  int ct_attribute=0;
  ifstream stream;
  string attribute;
  string attributeName;

  stream.open(path);

  if(!stream.is_open()){
    throw "Failed to open file : "+path;
  }

  while(getline(stream, attribute)){

    size_t found = attribute.rfind(": ");
    if (found!=string::npos){
      attributeName = attribute;
      attribute.erase(0,found+2);
      attributeName.erase(found, attributeName.back());
    }

    if (attributeName == "TYPE")
      _type=attribute;
    if (attributeName == "LABEL")
      _label=attribute;
    if (attributeName == "SIZE")
      _size=stoi(attribute);
    if (attributeName == "ACCESS")
      _access=stoi(attribute);
    if (attributeName == "SOURCE")
      _source=attribute;
  }

  infos();
  cout << "MEMORY loaded !" << endl;
  cout << "==================" << "\n"<< endl;

  stream.close();

}

void Memory::infos(){

  cout << "TYPE: " << _type << '\n'
       << "LABEL: " << _label << '\n'
       << "SIZE: " << _size << '\n'
       << "ACCESS: " << _access << '\n'
       << "SOURCE: " << _source << '\n' << endl;

}
