#
# Created by lukas koehler on 21.08.18.
#

cmake_minimum_required(VERSION 2.8)
project(cppunitTemplate)

set(CMAKE_CXX_STANDARD 14)

SET(CPPUNIT_FOUND "NO")
FIND_PATH(CPPUNIT_INCLUDE_DIR cppunit/TestCase.h /usr/local/include /usr/include)

FIND_LIBRARY(CPPUNIT_LIBRARY cppunit
        ${CPPUNIT_INCLUDE_DIR}/../lib
        /usr/local/lib
        /usr/lib)
FIND_LIBRARY(CPPUNIT_DEBUG_LIBRARY cppunit
        ${CPPUNIT_INCLUDE_DIR}/../lib
        /usr/local/lib
        /usr/lib)

IF (CPPUNIT_INCLUDE_DIR)
    IF (CPPUNIT_LIBRARY)
        SET(CPPUNIT_FOUND "YES")
        SET(CPPUNIT_LIBRARIES ${CPPUNIT_LIBRARY} ${CMAKE_DL_LIBS})
        SET(CPPUNIT_DEBUG_LIBRARIES ${CPPUNIT_DEBUG_LIBRARY} ${CMAKE_DL_LIBS})
    ELSE (CPPUNIT_LIBRARY)
        IF (CPPUNIT_FIND_REQUIRED)
            MESSAGE(SEND_ERROR "Could not find library CppUnit.")
        ENDIF (CPPUNIT_FIND_REQUIRED)
    ENDIF (CPPUNIT_LIBRARY)
ELSE (CPPUNIT_INCLUDE_DIR)
    IF (CPPUNIT_FIND_REQUIRED)
        MESSAGE(SEND_ERROR "Could not find library CppUnit.")
    ENDIF (CPPUNIT_FIND_REQUIRED)
ENDIF (CPPUNIT_INCLUDE_DIR)

add_executable(cppunitTemplate main.cpp MatrixTest.cpp MatrixTest.h MyXmlOutputterHook.cpp MyXmlOutputterHook.h MyXmlOutputterHook.cpp Matrix.cpp Matrix.h TeacherMatrix.cpp TeacherMatrix.h)
target_link_libraries(cppunitTemplate cppunit)