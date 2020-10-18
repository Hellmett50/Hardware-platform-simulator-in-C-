/*

██████╗ ██╗      █████╗ ████████╗███████╗ ██████╗ ██████╗ ███╗   ███╗    ███████╗██╗███╗   ███╗██╗   ██╗██╗      █████╗ ████████╗ ██████╗ ██████╗ 
██╔══██╗██║     ██╔══██╗╚══██╔══╝██╔════╝██╔═══██╗██╔══██╗████╗ ████║    ██╔════╝██║████╗ ████║██║   ██║██║     ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗
██████╔╝██║     ███████║   ██║   █████╗  ██║   ██║██████╔╝██╔████╔██║    ███████╗██║██╔████╔██║██║   ██║██║     ███████║   ██║   ██║   ██║██████╔╝
██╔═══╝ ██║     ██╔══██║   ██║   ██╔══╝  ██║   ██║██╔══██╗██║╚██╔╝██║    ╚════██║██║██║╚██╔╝██║██║   ██║██║     ██╔══██║   ██║   ██║   ██║██╔══██╗
██║     ███████╗██║  ██║   ██║   ██║     ╚██████╔╝██║  ██║██║ ╚═╝ ██║    ███████║██║██║ ╚═╝ ██║╚██████╔╝███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║
╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝    ╚══════╝╚═╝╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝
                                                                                                                                                  
*/

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

string getFileContents (ifstream& File)
{
    string Lines = "";        //All lines
    
    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    string TempLine;                  //Temp line
	    getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character
	    
	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
			return "ERROR File does not exist.";
}


int main(int argc, char* argv[]){

	/* ---------Logo---------*/

		ifstream Reader ("Logo.txt");             //Open file

    string Art = getFileContents (Reader);       //Get file
    
    cout << Art << endl;               //Print it to the screen

    Reader.close ();                           //Close file

	/*--------END Logo-------*/

  Platform platform;

  if( argc<2 )
    return EXIT_FAILURE;
  
  if(  platform.load( argv[1] ) == EXIT_FAILURE)
    return EXIT_FAILURE;

  platform.bind();

  platform.simulate();

	/* ---------Logo---------*/

		Reader.open("end.txt");             //Open file

    Art = getFileContents (Reader);       //Get file
    
    cout << Art << endl;               //Print it to the screen

    Reader.close ();                           //Close file

	/*--------END Logo-------*/
	
  cout << "//////////////////////THE END/////////////////////////" << endl;

  return EXIT_SUCCESS;
}
