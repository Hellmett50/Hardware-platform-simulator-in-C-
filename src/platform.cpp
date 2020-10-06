#include "../include/platform.hpp"

using namespace std;

Platform::Platform() : component_nb(0) {

}//End of Platform::Platform()

int Platform::load(string platformName){

  ifstream stream;
  string fileComponent;
  string ComponentType;

  Bus* bus_temp;
  Cpu*  cpu_temp;
  Memory* mem_temp;
  vector<Component*> componentTemp;

  cout << "//////////////////////// LOADING PLATFORM /////////////////////////////////" << endl;

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

  cout << "Platform loaded !" << endl;
  stream.close();
  if(stream.is_open()){
    cout << "Failed to close file : " << platformName << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;

}//End of Platform::load()

void Platform::bind(){

  cout << "////////////////////INITIATING PLATFORM BINDING/////////////////////////////" << endl;

  hardWareTemp[0]->_source = hardWareTemp[2];//mem
  hardWareTemp[1]->_source = hardWareTemp[3];//mem
  hardWareTemp[2]->_source = hardWareTemp[4];
  hardWareTemp[3]->_source = hardWareTemp[5];
  display->_source = hardWareTemp[0];

}//End of Platform::bind()

void Platform::simulate(){

  cout << "////////////////////INITIATING PLATFORM SIMULATION/////////////////////////////" << endl;

  for (int a = 0; a < 20; a++) {
    for (size_t j = 0; j < component_nb-1; j++) {
      hardWareTemp[j]->simulate();
    }
    display->simulate();
  }

}//End of Platform::simulate()
