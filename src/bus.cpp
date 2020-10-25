#include "../include/bus.hpp"

using namespace std;

Bus::Bus(string path){

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
      _sourceLabel=attribute;
  }


  infos();
  cout << "BUS loaded !" << endl;
  cout << "==================" << "\n"<< endl;

  stream.close();

}
/*
Bus::~Bus(){
  delete _pendingValues[_width];
}*/
/*
string Bus::tellLabelSource() const{
  return _sourceLabel;
}//End of Bus::tellLabelSource()
*/
void Bus::infos() const{

  cout << "TYPE: " << _type << '\n'
       << "LABEL: " << _label << '\n'
       << "WIDTH: " << _width << '\n'
       << "SOURCE: " << _sourceLabel << '\n' << endl;

}

void Bus::simulate(){

  cout << "\nSimulating BUS("+_label+")...\n" << endl;
  while (!_pendingValues.empty()) {
    cout << "pending->ready" << endl;
    _readyValues.push(_pendingValues.front());
    _pendingValues.pop();

  }
  for (unsigned int i = 0; i < _width; i++) {

    pair<bool, double> dataValue = _source->read();

    if (dataValue.first) {
      _pendingValues.push(dataValue);
    }
    else
      break;

  }
  cout << "End of Bus("+_label+") simulation.\n" << endl;
}//End of Bus::simulate()


pair<bool, double> Bus::read() {

  pair<bool, double> output;
  cout << "Reading "+_label+"..." << endl;
  if (_readyValues.empty()) {
    output.first = false;
    cout << _label+" IS EMPTY: " << output.first << endl;
    return output;
  }
  output = _readyValues.front();
  _readyValues.pop();

  cout << "First available value in "+_label+" is : " << output.second << endl;
  return output;

}//End of Bus:read()
