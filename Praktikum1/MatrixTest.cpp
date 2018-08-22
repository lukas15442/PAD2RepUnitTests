//
// Created by lukas koehler on 21.08.18.
//

#include "MatrixTest.h"

void MatrixTest::setUp() {
    TestFixture::setUp();
}

void MatrixTest::tearDown() {
    TestFixture::tearDown();
}

void MatrixTest::testConstructors() {
    {
        Matrix m(3, 4);
        CPPUNIT_ASSERT_MESSAGE("After Matrix m(3, 4); m should have rows 3", m.getRows() == 3);
        CPPUNIT_ASSERT_MESSAGE("After Matrix m(3, 4); m should have cols 4", m.getCols() == 4);
    }
    {
        Matrix m(1, 5, 5.0);
        CPPUNIT_ASSERT_MESSAGE("After Matrix m(1, 5, 5.0); m should have rows 1", m.getRows() == 1);
        CPPUNIT_ASSERT_MESSAGE("After Matrix m(1, 5, 5.0); m should have cols 5", m.getCols() == 5);
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 5; j++) {
                if (m.at(i, j) != 5.0) {
                    CPPUNIT_FAIL("After Matrix m(1, 5, 5.0); not all values are 5.0");
                }
            }
        }
    }
    {
        Matrix m(6, 1, -5.1);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 1; j++) {
                if (m.at(i, j) != -5.1) {
                    CPPUNIT_FAIL("After Matrix m(1, 5, -5.1); not all values are -5.1");
                }
            }
        }
    }
    {
        try {
            Matrix m(0, 1, -5.1);
            CPPUNIT_FAIL("After Matrix m(0, 1, -5.1); should fail");
        } catch (...) {
        }
    }
    {
        try {
            Matrix m(3, -1, -5.1);
            CPPUNIT_FAIL("After Matrix m(3, -1, -5.1); should fail");
        } catch (...) {
        }
    }
    {
        try {
            Matrix m(0, 1);
            CPPUNIT_FAIL("After Matrix m(0, 1); should fail");
        } catch (...) {
        }
    }
    {
        try {
            Matrix m(3, -1);
            CPPUNIT_FAIL("After Matrix m(3, -1); should fail");
        } catch (...) {
        }
    }
}

void MatrixTest::testCopyConstructor() {
    Matrix m1(3, 5, 3.0);
    Matrix m2(m1);

    CPPUNIT_ASSERT_MESSAGE("After Matrix m1(3, 5, 3.0); Matrix m2(m1); rows of m1 and m2 not the same",
                           m2.getRows() == m1.getRows());
    CPPUNIT_ASSERT_MESSAGE("After Matrix m1(3, 5, 3.0); Matrix m2(m1); cols of m1 and m2 not the same",
                           m2.getCols() == m1.getCols());

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (m1.at(i, j) != 3.0) {
                CPPUNIT_FAIL("After Matrix m1(3, 5, 3.0); Matrix m2(m1); m1 does not contain 3.0 as values anymore");
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (m2.at(i, j) != 3.0) {
                CPPUNIT_FAIL("After Matrix m1(3, 5, 3.0); Matrix m2(m1); m2 does not contain 3.0 as values");
            }
        }
    }

    m1.at(0, 0) = 5;
    CPPUNIT_ASSERT_MESSAGE("After m1.at(0, 0) = 5; m1.at(0, 0) does not contain 5", m1.at(0, 0) == 5);
    CPPUNIT_ASSERT_MESSAGE("After m1.at(0, 0) = 5; m2.at(0, 0) does not contain 3 anymore", m2.at(0, 0) == 3);

    m2.at(1, 1) = 8;
    CPPUNIT_ASSERT_MESSAGE("After m2.at(1, 1) = 8; m2.at(1, 1) does not contain 8", m2.at(1, 1) == 8);
    CPPUNIT_ASSERT_MESSAGE("After m2.at(1, 1) = 8; m1.at(1, 1) does not contain 3 anymore", m1.at(1, 1) == 3);
}

void MatrixTest::testConstCorrectness() {
    Matrix m(6, 2, 7);
    testConst(m);
}

void MatrixTest::testConst(const Matrix &m) {
    CPPUNIT_ASSERT_MESSAGE("After Matrix m(6, 2, 7); const m should contain 7 at (0, 0)", m.at(0, 0) == 7);
}

void MatrixTest::testOutOfRange() {
    try {
        Matrix m(13, 11, 3);
        m.at(13, 10) = 5;
        CPPUNIT_FAIL("After Matrix m(13, 11, 3); m.at(13, 10) = 5; should fail");
    } catch (...) {
    }

    try {
        Matrix m(13, 11, 3);
        m.at(12, 11) = 5;
        CPPUNIT_FAIL("After Matrix m(13, 11, 3); m.at(12, 11) = 5; should fail");
    } catch (...) {
    }

    try {
        Matrix m(13, 11, 3);
        m.at(-1, 0) = 5;
        CPPUNIT_FAIL("After Matrix m(13, 11, 3); m.at(-1, 0) = 5; should fail");
    } catch (...) {
    }

    try {
        Matrix m(13, 11, 3);
        m.at(0, -1) = 5;
        CPPUNIT_FAIL("After Matrix m(13, 11, 3); m.at(0, -1) = 5; should fail");
    } catch (...) {
    }
}




