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

  cout << "//////////////////////// LOADING PLATFORM /////////////////////////////////" << endl;

  stream.open(platformName);

  if(!stream.is_open()){
    cout << "Failed to open file : " << platformName << endl;
    return EXIT_FAILURE;
  }

  while(getline(stream, fileComponent)){
      deleteSpace(fileComponent);
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
          hardWareTemp[component_nb]->infos();
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
      std::cout << "ComponentType2: " << ComponentType << '\n' << '\n';
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

  for(int component_id=0; component_id<component_nb-1; component_id++)
  {
    for(int source_id = 0; source_id < component_nb-1; source_id++)
    {
      if (hardWareTemp[component_id]->tellLabelSource() == hardWareTemp[source_id]->tellLabel())
      {
        hardWareTemp[component_id]->bind(hardWareTemp[source_id]);
        break;
      }
    }
    if(display->tellLabelSource() == hardWareTemp[component_id]->tellLabel()){
      display->bind(hardWareTemp[component_id]);
    }
  }

}//End of Platform::bind()

int Platform::simulate( int imax ){

  if( imax < 0 ){
    cout << "ERROR : wrong cycle number" << endl;
    return EXIT_FAILURE;
  }
  cout << "////////////////////INITIATING PLATFORM SIMULATION/////////////////////////////" << endl;

  for (int i = 0; i < imax; i++) {
    for (int j = 0; j < component_nb-1; j++) {
      hardWareTemp[j]->simulate();
    }
    display->simulate();
  }
  return EXIT_SUCCESS;

}//End of Platform::simulate()
