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

  while(!stream.eof()){

    getline(stream, attribute);
    size_t found = attribute.rfind(": ");
    if (found!=string::npos)
      attribute.erase(0,found+2);

    switch (ct_attribute) {
      case TYPE:
      attribute.erase(remove(attribute.begin(), attribute.end(), ' '), attribute.end());
        _type=attribute;
      break;
      case REFRESH:
        _refresh=stoi(attribute);
      break;
      case SOURCE:
        deleteSpace(attribute);
        _sourceLabel=attribute;
      break;
    }
    ct_attribute++;
  }

  infos();
  cout << "DISPLAY loaded !" << endl;
  cout << "==================" << "\n"<< endl;

  stream.close();

}//End of Display::Display()

void Display::infos() const{

  cout << "TYPE: " << _type << '\n'
       << "REFRESH: " << _refresh << '\n'
       << "SOURCE: " << _sourceLabel<< '\n' << endl;

}//End of Display::infos()

void Display::tellLabelSource() const{
  cout << "Source's Label of component DISPLAY : "+_sourceLabel<< endl;
}//End of Display::tellLabelSource()

void Display::simulate(){

  pair<bool, double> dataValue;

  cout << "\nSimulating DISPLAY...\n" << endl;


  for(unsigned int i=0; i< _refresh; i++){
    dataValue = _source->read();
    if(!dataValue.first){
      cout << "Invalid DataValue - Cannot read it..." << endl;
      break;
    }
    cout << "Value : " << dataValue.second << endl;
  }

  cout << "End of DISPLAY simulation.\n" << endl;

}//End of Display::simulate()
