#ifndef MEM_H
#define MEM_H

#include <iostream>
#include <string>
#include "hardware.hpp"
#include "bus.hpp"

class CircBuffer{
  private:
    std::pair<bool, double>* _buffer;
    unsigned int _head;
    unsigned int _tail;

  public:
    unsigned int _size;
    CircBuffer(unsigned int size);
    int pushData(std::pair<bool, double> data);
    int popData(std::pair<bool, double>& data);
};


class Memory : public Component{
  private:
    unsigned int _access;
    CircBuffer* _circbuffer;
    unsigned int _accesCt;

  public:
    void tellLabelSource() const;
    Memory(std::string path);
    void infos() const;
    void bind();
    void simulate();
    std::pair<bool, double> read();
};


#endif
