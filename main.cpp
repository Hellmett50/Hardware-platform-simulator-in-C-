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

//-------------------------------------------------------

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>

#include "./test/testCpu.hpp"

using namespace CppUnit;

//--------------------------------------------------

#include "./include/notify.hpp"
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
	
	if( argc<2 ){
    cout << "ERROR : too few arguments" << endl;
    return EXIT_FAILURE;
  }
	
	if(!strcmp(argv[1],"test")){
		//informs test-listener about testresults
		CPPUNIT_NS::TestResult testResult;

		// register listener for collecting the test-results
		CPPUNIT_NS::TestResultCollector collectedResults;
		testResult.addListener (&collectedResults);

		// register listener for per-test progress output
		CPPUNIT_NS::BriefTestProgressListener progress;
		testResult.addListener(&progress);

		// Get the top level suite from the registry
		Test *suite = TestFactoryRegistry::getRegistry().makeTest();

		// Adds the test to the list of test to run
		TextUi::TestRunner runner;
		runner.addTest( suite );

		// Change the default outputter to a compiler error format outputter
		runner.setOutputter( new CompilerOutputter(&runner.result(), cerr) );
		// output results in compiler-format
		CPPUNIT_NS::CompilerOutputter compilerOutputter(&collectedResults, cerr);
		// Run the tests.
		runner.run(testResult);
		compilerOutputter.write();

		// Return error code 1 if the one of test failed.
		return collectedResults.wasSuccessful() ? 0 : 1;
	}

  Platform platform;

  if( argc<3 ){
    cout << "ERROR : too few arguments" << endl;
    return EXIT_FAILURE;
  }

  if(  platform.load( argv[1] ) == EXIT_FAILURE) {
    cout << "ERROR : no file or wrong file specified" << endl;
    return FILE_OPEN_FAILURE;
  }

  platform.bind();

  if(  platform.simulate( stoi(argv[2]) ) == EXIT_FAILURE){
    cout << "ERROR : no simulating cycle specified" << endl;
    return EXIT_FAILURE;
  }

	/* ---------Logo---------*/

		Reader.open("end.txt");             //Open file

    Art = getFileContents (Reader);       //Get file

    cout << Art << endl;               //Print it to the screen

    Reader.close ();                           //Close file

	/*--------END Logo-------*/

  cout << "//////////////////////THE END/////////////////////////" << endl;

  return EXIT_SUCCESS;
}
