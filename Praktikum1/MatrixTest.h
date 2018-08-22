//
// Created by lukas koehler on 21.08.18.
//

#ifndef CODELUKAS_MYTEST_H
#define CODELUKAS_MYTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Matrix.h"
#include "TeacherMatrix.h"

class MatrixTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(MatrixTest);
            CPPUNIT_TEST(testConstructors);
            CPPUNIT_TEST(testCopyConstructor);
            CPPUNIT_TEST(testConstCorrectness);
            CPPUNIT_TEST(testOutOfRange);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;

    void tearDown() override;

    void testConstructors();

    void testCopyConstructor();

    void testConstCorrectness();

    void testOutOfRange();

    void testConst(const Matrix& m);
};

#endif //CODELUKAS_MYTEST_H
