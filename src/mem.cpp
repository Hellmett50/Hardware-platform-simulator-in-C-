#include "../include/mem.hpp"

using namespace std;

Memory::Memory(string path) {

  cout << "\n\n==================\n"
       << "Loading component MEMORY...\n" << endl;

  ifstream stream;
  string attribute;
  string attributeName;
  _accesCt = 0;
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
      _circbuffer = new CircBuffer(stoi(attribute));
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

Memory::~Memory(){
  delete _circbuffer;
}

void Memory::infos() const{

  cout << "TYPE: " << _type << '\n'
       << "LABEL: " << _label << '\n'
       << "SIZE: " << _circbuffer->_size << '\n'
       << "ACCESS: " << _access << '\n'
       << "SOURCE: " << _source << '\n' << endl;

}

void Memory::bind(/*Bus* bus*/) {
  //_bus = bus;
}

void Memory::simulate(){

    cout << "\nSimulating MEMORY...\n" << endl;
    if (_accesCt % _access == 0) {
      pair<bool, double> dataValue = _bus->read();
      while(dataValue.first){
        if (_circbuffer->pushData(dataValue)) {
          cout << "CANNOT PUSH" << '\n';
        }
        cout << "mem = " << dataValue.second << '\n';
        dataValue = _bus->read();
      }
      _accesCt++;
    cout << "End of Memory simulation.\n" << endl;
  }
}

pair<bool, double> Memory::read() {
  pair<bool, double> output;
  if(_circbuffer->popData(output)){
    cout << "CANNOT POP" << '\n';
  }
  return output;
}

CircBuffer::CircBuffer(unsigned int size) {
  _size = size;
  _tail = 0;
  _head = 0;
  _buffer = new pair<bool, double>[size];
}

int CircBuffer::pushData(pair<bool, double> data){
    unsigned int next;
    next = _head + 1;  // next is where head will point to after this write.
    if (next >= _size)
        next = 0;

    if (next == _tail)  // if the head + 1 == tail, circular buffer is full
        return -1;

    _buffer[_head] = data;  // Load data and then move
    _head = next;             // head to next data offset.
    return 0;  // return success to indicate successful push.
}

int CircBuffer::popData(pair<bool, double>& data){
    unsigned int next;

    if (_head == _tail)  // if the head == tail, we don't have any data
        return -1;

    next = _tail + 1;  // next is where tail will point to after this read.
    if(next >= _size)
        next = 0;

    data = _buffer[_tail];  // Read data and then move
    _tail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}
