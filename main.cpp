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
  size_t component_nb=1;

  stream.open(platformName);

  if(!stream.is_open()){
    cout << "Failed to open file : " << platformName << endl;
    return EXIT_FAILURE;
  }

  while(getline(stream, fileComponent)){

      vector<HardWare*> hardWareTemp;
      ComponentType = fileComponent;

      size_t found = ComponentType.rfind("/");
      if (found!=string::npos)
        ComponentType.erase(0,found+1);

      found = ComponentType.find_first_of("123456789.");
      if (found!=string::npos)
        ComponentType.erase(found,ComponentType.back());

      cout << ComponentType << endl;

      if(ComponentType=="bus"){
        try
        {
          Bus bus_temp(fileComponent);
          hardWareTemp.resize(component_nb,&bus_temp);
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
          Cpu cpu_temp(fileComponent);
          hardWareTemp.resize(component_nb,&cpu_temp);

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
          Display disp_temp(fileComponent);
          hardWareTemp.resize(component_nb,&disp_temp);
          //hardWareTemp[6]->tellLabelSource();
          hardWareTemp[6]->simulate();
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
          Memory mem_temp(fileComponent);
          hardWareTemp.resize(component_nb,&mem_temp);
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

  cout << "Platform loaded !" << endl;
  stream.close();
  if(stream.is_open()){
    cout << "Failed to close file : " << platformName << endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
