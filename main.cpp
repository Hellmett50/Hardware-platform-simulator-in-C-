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
#include "./include/platform.hpp"

using namespace std;



int main(int argc, char* argv[]){

  Platform platform;

  if( platform.load(argv[1]) )
    return EXIT_FAILURE;

  platform.bind();

  platform.simulate();

  cout << "//////////////////////THE END/////////////////////////" << endl;

  return EXIT_SUCCESS;
}
