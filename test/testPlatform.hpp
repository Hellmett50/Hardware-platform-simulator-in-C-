#ifndef _TEST_PLATFORM_
#define _TEST_PLATFORM_

#include <iostream>
#include <string>
#include <cppunit/extensions/HelperMacros.h>

#include "../include/platform.hpp"

class TestPlatform : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPlatform);
    CPPUNIT_TEST(testLoadingSuccess);
    //CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testLoadingSuccess(void);
    //void testMultiply(void);

private:

    Platform *platform;
};

#endif
