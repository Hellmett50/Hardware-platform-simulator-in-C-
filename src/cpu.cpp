#include "../include/cpu.hpp"

using namespace std;


/*============Cpu============*/
Cpu::Cpu(string path){

  cout << "\n\n==================\n"
       << "Loading component CPU...\n" << endl;

  int ct_attribute=0;
  ifstream stream;
  string attribute;

  stream.open(path);

  if(!stream.is_open())
    throw "Failed to open file : "+path;

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
      case LABEL:
      deleteSpace(attribute);
        _label=attribute;
      break;
      case CORES:
        _cores=stoi(attribute);
      break;
      case FREQUENCY:
        _freq=stoi(attribute);
      break;
      case PROGRAM:
      attribute.erase(remove(attribute.begin(), attribute.end(), ' '), attribute.end());
        _prog.loadProgram(attribute);
      break;
    }
    ct_attribute++;
  }

  infos();
  cout << "CPU loaded !" << endl;
  cout << "==================" << "\n"<< endl;

  stream.close();
  if(stream.is_open())
    throw "Failed to close file : "+path;

}//End of Cpu::Cpu()

void Cpu::infos() const{

  cout << "TYPE: " << _type << '\n'
       << "LABEL: " << _label << '\n'
       << "CORES: " << _cores << '\n'
       << "FREQUENCY: " << _freq << endl;
       _prog.printPath();

}//End of Cpu::info()

void Cpu::simulate(){

  cout << "\nSimulating...\n" << endl;
  cout << "Computing instructions...\n\n" << endl;

  for(unsigned int i=0; i<_freq; i++){
    if(_prog.finished()){
      _prog.printInstruction();
      cout << "\nEnd of program : ";
      _prog.printPath();
      break;
    }
    else
      _reg.write(_prog.compute());
  }

  cout << "\nEnd of computation.\n" << endl;
  cout << "End of simulation.\n" << endl;

}//End of Cpu::simulate()

map<bool, double> Cpu::read() const{

  map<bool, double> output;

  cout << "Reading CPU..." << endl;

  if(_reg.isEmpty()){
    output[false];
  }
  else{
    output[true]=_reg.read();
    cout << "First available value in the register is : " << output[true] << endl;
  }

  return output;

}//End of Cpu::read()


/*============Instruction============*/
double Instruction::compute() const{

  if(_opCode=="ADD"){
    return _op1+_op2;
  }
  else if(_opCode=="SUB"){
    return _op1-_op2;
  }
  else if(_opCode=="MUL"){
    return _op1*_op2;
  }
  else if(_opCode=="DIV"){
    return _op1/_op2;
  }
  else
  return 0;

}//End of Instruction::compute()

void Instruction::getInstruction(string opCode, double op1, double op2){

  _opCode = opCode;
  _op1 = op1;
  _op2 = op2;

}//End of Instruction::getInstruction()

void Instruction::printInstruction() const{

  cout << _opCode + " " + to_string(_op1) + " " + to_string(_op2) << endl;

}//End of Instruction::printInstruction()


/*============Program============*/
Program::Program() : _pc(0){

}//End of Program::Program()

void Program::loadProgram(string path){

  cout << "Loading program " << path << "...\n" << endl;

  ifstream stream;
  Instruction inst_temp;
  string instruction;
  string opCode;
  double op1, op2;
  int i=0;

  _path=path;

  stream.open(_path);

  if(!stream.is_open())
    throw "Failed to load the program : "+_path;

  while(!stream.eof()){
    stream >> opCode;
    cout << opCode << endl;
    stream >> op1;
    cout << op1 << endl;
    stream >> op2;
    cout << op2 << endl;
    inst_temp.getInstruction(opCode, op1, op2);
    _inst.push_back(inst_temp);
    cout << "resultat : " << _inst[i].compute() << endl;
    i++;
  }
  inst_temp.getInstruction("NOP", 0, 0);
  _inst.push_back(inst_temp);
  stream.close();

  if(stream.is_open())
    throw "Failed to close program : "+_path;

  else
    cout << "\nProgram loaded !\n" << endl;

}//End of Program::loadProgram()

double Program::compute(){

        _inst[_pc].printInstruction();
        _result = _inst[_pc].compute();
        _pc++;
        cout << "\nresult = " << _result << " pc = " << _pc << '\n' << endl;
        return _result;

}//End of Program::compute()

bool Program::finished() const{

  if(_pc>=_inst.size()-1)
    return true;
  else
    return false;

}//End of Program::finished()

void Program::printInstruction() const{

  _inst[_pc].printInstruction();

}//End of Program::printInstruction()

void Program::printPath() const{
  cout << "PROGRAM: " << _path << '\n' << endl;
}//End of Program::printPath()

void Program::reset(){

  _pc=0;

}//End of Program::reset()


/*============Register============*/
bool Register::isEmpty() const{

  cout << "Reading register...\n" << endl;

  if(_value.empty()){
    cout << "Register is empty." << endl;
    return true;
  }
  else{
    cout << "Register isn't empty." << endl;
    return false;
  }

}//End of Register::isEmpty()

double Register::read() const{

  return _value.back();

}//End of Register::read()

void Register::write(double value){

  _value.push(value);

}//End of Register::write()
