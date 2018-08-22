//
// Created by lukas koehler on 21.08.18.
//

#include <iostream>

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/XmlOutputter.h>
#include "MyXmlOutputterHook.h"
#include "MatrixTest.h"

const char *PROJECT_NAME = "PROJECT_NAME";
const char *AUTHOR = "AUTHOR";
const char *XML_FILE_NAME = "testResults.xml";

int main() {
    CppUnit::TextUi::TestRunner runner;
    std::ofstream outputFile(XML_FILE_NAME);

    CppUnit::XmlOutputter *outputter = new CppUnit::XmlOutputter(&runner.result(),
                                                                 outputFile);
    MyXmlOutputterHook hook(PROJECT_NAME, AUTHOR);
    outputter->addHook(&hook);
    runner.setOutputter(outputter);
    runner.addTest(MatrixTest::suite());
    runner.run();
    outputFile.close();

    return 0;
}