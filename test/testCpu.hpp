#ifndef _TEST_CPU_
#define _TEST_CPU_

#include <iostream>
#include <string>
#include <cppunit/extensions/HelperMacros.h>

#include "../include/cpu.hpp"
#include "../include/notify.hpp"

//-----------------------------------------------------------------------------

class TestCpu : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestCpu);
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

    Cpu *cpu;
};

#endif
