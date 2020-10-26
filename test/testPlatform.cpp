#include "testPlatform.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION( TestPlatform ); //start the test

void TestPlatform::testLoadingSuccess(void)
{
    CPPUNIT_ASSERT(platform->load("testdata/platform.txt") == LOADING_SUCCESS);
}

/*void TestCpu::testMultiply(void)
{
    //CPPUNIT_ASSERT();
}
*/
void TestPlatform::setUp(void)
{
    platform = new Platform();
}

void TestPlatform::tearDown(void)
{
    delete platform;
}
