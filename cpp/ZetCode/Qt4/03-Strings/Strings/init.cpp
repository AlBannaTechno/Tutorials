#include "strings.h"
#include <QtCore/QTextStream>


int init() {
    QTextStream out(stdout);
    
    QString str1 = "The night train";
    out << str1 << endl;
    
    QString str2("A yellow rose");
    out << str2 << endl;
    
    std::string s1 = "A blue sky";
    QString str3 = s1.c_str();
    out << str3 << endl;
    
    std::string s2 = "A think fog";
    QString str4 = QString::fromAscii(s2.data(), s2.size());
    out << str4 << endl;
    
    char s3[] = "A deep forest";
    QString str5(s3);
    out << str5 << endl;
    
    return 0;
}
