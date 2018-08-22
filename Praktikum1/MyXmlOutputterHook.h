//
// Created by lukas koehler on 21.08.18.
//
// Created by lukas koehler on 21.08.18.
//

#ifndef CODELUKAS_MYXMLOUTPUTTERHOOK_H
#define CODELUKAS_MYXMLOUTPUTTERHOOK_H

#include <cppunit/XmlOutputterHook.h>
#include <cppunit/tools/StringTools.h>
#include <cppunit/tools/XmlDocument.h>
#include <cppunit/tools/XmlElement.h>

class MyXmlOutputterHook : public CppUnit::XmlOutputterHook {
public:
    MyXmlOutputterHook(const std::string projectName,
                       const std::string author) {
        m_projectName = projectName;
        m_author = author;
    };

    virtual ~MyXmlOutputterHook() {
    };

    void beginDocument(CppUnit::XmlDocument *document) {
        if (!document)
            return;

        std::string szDate = CppUnit::StringTools::toString((int) time(0));
        CppUnit::XmlElement *metaEl = new CppUnit::XmlElement("SuiteInfo",
                                                              "");

        metaEl->addElement(new CppUnit::XmlElement("Author", m_author));
        metaEl->addElement(new CppUnit::XmlElement("Project", m_projectName));
        metaEl->addElement(new CppUnit::XmlElement("Date", szDate));

        document->rootElement().addElement(metaEl);
    };
private:
    std::string m_projectName;
    std::string m_author;
};

#endif //CODELUKAS_MYXMLOUTPUTTERHOOK_H
