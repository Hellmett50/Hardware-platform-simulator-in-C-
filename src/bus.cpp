#include "../include/bus.hpp"

using namespace std;

Bus::Bus(string path){

  cout << "Je suis un bus !!" << '\n';
  cout << path << endl;
  cout << "\n\n==================\n"
       << "Loading component BUS...\n" << endl;

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
    if (attributeName == "WIDTH")
      _width=stoi(attribute);
    if (attributeName == "SOURCE")
      _source=attribute;
  }


  infos();
  cout << "BUS loaded !" << endl;
  cout << "==================" << "\n"<< endl;

  stream.close();

}

void Bus::infos() const{

  cout << "TYPE: " << _type << '\n'
       << "LABEL: " << _label << '\n'
       << "WIDTH: " << _width << '\n'
       << "SOURCE: " << _source << '\n' << endl;

}

void Bus::simulate(){

}//End of Bus::simulate()

void Bus::read() {
  
}
