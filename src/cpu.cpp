#include "../include/cpu.hpp"

using namespace std;

Cpu::Cpu(string path){

  cout << "\n\n==================\n"
       << "Loading component CPU...\n" << endl;

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
      case LABEL:
        _label=attribute;
      break;
      case CORES:
        _cores=stoi(attribute);
      break;
      case FREQUENCY:
        _freq=stoi(attribute);
      break;
      case PROGRAM:
        _program=attribute;
      break;
    }
    ct_attribute++;
  }

  infos();
  cout << "CPU loaded !" << endl;
  cout << "==================" << "\n"<< endl;

  stream.close();

}

void Cpu::infos(){

  cout << "TYPE: " << _type << '\n'
       << "LABEL: " << _label << '\n'
       << "CORES: " << _cores << '\n'
       << "FREQUENCY: " << _freq << '\n'
       << "PROGRAM: " << _program << '\n' << endl;

}

void Cpu::simulate(){

  ifstream stream;
  string instruction;
  string opCode;
  double op1, op2;

  stream.open(_program);

  if(!stream.is_open()){
    throw "Failed to open file : "+_program;
  }

  while(!stream.eof()){
    stream >> opCode;
    cout << opCode << endl;
    stream >> op1;
    cout << op1 << endl;
    stream >> op2;
    cout << op2 << endl;
    opCode.clear();
  }
  stream.close();

}
