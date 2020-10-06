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
  size_t component_nb=0;

  Bus* bus_temp;
  Cpu*  cpu_temp;
  Memory* mem_temp;
  vector<HardWare*> hardWareTemp;
  vector<Component*> componentTemp;
  Display* display;

  stream.open(platformName);

  if(!stream.is_open()){
    cout << "Failed to open file : " << platformName << endl;
    return EXIT_FAILURE;
  }

  while(getline(stream, fileComponent)){

      ComponentType = fileComponent;

      size_t found = ComponentType.rfind("/");
      if (found!=string::npos)
        ComponentType.erase(0,found+1);

      found = ComponentType.find_first_of("123456789.");
      if (found!=string::npos)
        ComponentType.erase(found,ComponentType.back());

      //cout << ComponentType << endl;

      if(ComponentType=="bus"){
        try
        {
          bus_temp = new Bus(fileComponent);
          hardWareTemp.push_back(bus_temp);
          hardWareTemp[component_nb]->infos();
        }
        catch(const string msg)
        {
          cout << msg << endl;
          return EXIT_FAILURE;
        }
      }

      else if(ComponentType=="cpu"){
        try
        {
          cpu_temp = new Cpu(fileComponent);
          hardWareTemp.push_back(cpu_temp);
          hardWareTemp[component_nb]->infos();
/*
          cout << "\n===========READ============"<< endl;
          //hardWareTemp[4]->infos();
          //hardWareTemp[4]->read();
          hardWareTemp[4]->simulate();
          cout << "\n===========READ============" << endl;
          //hardWareTemp[4]read();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          hardWareTemp[4]->simulate();
          cout << "\n===========READ============" << endl;
          //hardWareTemp[4]->read();
*/
        }
        catch (const string msg)
        {
          cout << msg << endl;
          return EXIT_FAILURE;
        }
      }

      else if(ComponentType=="mem"){
        try
        {
          mem_temp = new Memory(fileComponent);
          hardWareTemp.push_back(mem_temp);
          hardWareTemp[0]->infos();
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
          display = new Display(fileComponent);

        }
        catch (const string msg)
        {
          cout << msg << endl;
          return EXIT_FAILURE;
        }
      }
      else{
        cout << "Failled to load the Platform..." << endl;
        return EXIT_FAILURE;
      }
      component_nb++;
  }

  /*getline(stream, fileComponent);
  Memory mem(fileComponent);
  getline(stream, fileComponent);
  Bus bus(fileComponent);
  getline(stream, fileComponent);
  Cpu cpu(fileComponent);
  getline(stream, fileComponent);
  Display display(fileComponent);
  mem._bus = &bus;
  bus._cpu = &cpu;
  display._mem = &mem;
  for (int a = 0; a < 50; a++) {
    cpu.simulate();
    bus.simulate();
    mem.simulate();
    display.simulate();
  }*/

  cout << "Platform loaded !" << endl;
  stream.close();
  if(stream.is_open()){
    cout << "Failed to close file : " << platformName << endl;
    return EXIT_FAILURE;
  }

  cout << "////////////////////INITIATING PLATFORM BINDING/////////////////////////////" << endl;

  hardWareTemp[0]->_source = hardWareTemp[2];//mem
  hardWareTemp[1]->_source = hardWareTemp[3];//mem
  hardWareTemp[2]->_source = hardWareTemp[4];
  hardWareTemp[3]->_source = hardWareTemp[5];
  display->_source = hardWareTemp[0];


  cout << "////////////////////INITIATING PLATFORM SIMULATION/////////////////////////////" << endl;

  for (int a = 0; a < 20; a++) {
    for (size_t j = 0; j < component_nb-1; j++) {
      hardWareTemp[j]->simulate();
    }
    display->simulate();
  }

  cout << "//////////////////////THE END/////////////////////////" << endl;

  return EXIT_SUCCESS;
}
