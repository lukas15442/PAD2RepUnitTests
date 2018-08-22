//
// Created by lukas koehler on 21.08.18.
//

#ifndef CODELUKAS_MYTEST_H
#define CODELUKAS_MYTEST_H

#include <cppunit/extensions/HelperMacros.h>

class MyTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(MyTest);
        CPPUNIT_TEST(myTestFunction);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;

    void tearDown() override;

    void myTestFunction();
};

#endif //CODELUKAS_MYTEST_H
