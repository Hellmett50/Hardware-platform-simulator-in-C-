#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>

#include "./include/hardware.hpp"
#include "./include/mem.hpp"
#include "./include/bus.hpp"
#include "./include/cpu.hpp"
#include "./include/display.hpp"

using namespace std;



int main(int argc, char* argv[]){

  ifstream stream;
  string platformName = argv[1];
  string fileComponent;
  string ComponentType;

  stream.open(platformName);
  while(getline(stream, fileComponent)!=0){

      HardWare* hardWareTemp;
      ComponentType = fileComponent;

      size_t found = ComponentType.rfind("/");
      if (found!=string::npos)
      ComponentType.erase(0,found+1);

      found = ComponentType.find_first_of("123456789.");
      if (found!=string::npos)
      ComponentType.erase(found,ComponentType.back());

      cout << ComponentType << endl;

      if(ComponentType=="bus"){
        hardWareTemp = new Bus(fileComponent);
      }

      else if(ComponentType=="cpu"){
        hardWareTemp = new Cpu(fileComponent);
      }

      else if(ComponentType=="display"){
        hardWareTemp = new Display(fileComponent);
      }

      else if(ComponentType=="mem"){
        hardWareTemp = new Memory(fileComponent);
      }

  }


  return 0;
}
