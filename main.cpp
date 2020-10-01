#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include <exception>

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

  if(!stream.is_open()){
    cout << "Failed to open file : " << platformName << endl;
    return EXIT_FAILURE;
  }

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
        try
        {
          Cpu* l = new Cpu(fileComponent);
          l->simulate();
        }
        catch (const string msg)
        {
          cout << msg << endl;
          return EXIT_FAILURE;
        }
      }

      else if(ComponentType=="display"){
        try
        {
          hardWareTemp = new Display(fileComponent);
        }
        catch (const string msg)
        {
          cout << msg << endl;
          return EXIT_FAILURE;
        }
      }

      else if(ComponentType=="mem"){
        hardWareTemp = new Memory(fileComponent);
      }
      else{
        cout << "Failled to load the Platform..." << endl;
        return EXIT_FAILURE;
      }

  }
  cout << "Platform loaded !" << endl;
  stream.close();
  if(stream.is_open()){
    cout << "Failed to close file : " << platformName << endl;
    return EXIT_FAILURE;
  }


  return 0;
}
