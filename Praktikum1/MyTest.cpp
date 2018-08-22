//
// Created by lukas koehler on 21.08.18.
//

#include "MyTest.h"

void MyTest::setUp() {
    TestFixture::setUp();
}

void MyTest::tearDown() {
    TestFixture::tearDown();
}

void MyTest::myTestFunction() {
    CPPUNIT_ASSERT(1 == 2);
}
