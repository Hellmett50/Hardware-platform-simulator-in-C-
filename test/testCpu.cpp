#include "testCpu.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION( TestCpu ); //start the test

void TestCpu::testLoadingSuccess(void)
{
    CPPUNIT_ASSERT(cpu->load("testdata/cpu1.txt") == LOADING_SUCCESS);
}

/*void TestCpu::testMultiply(void)
{
    //CPPUNIT_ASSERT();
}
*/
void TestCpu::setUp(void)
{
    cpu = new Cpu();
}

void TestCpu::tearDown(void)
{
    delete cpu;
}

