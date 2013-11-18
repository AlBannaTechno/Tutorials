#include "strings.h"
#include <QtCore/QTextStream>


int length() {
    QTextStream out(stdout);
    
    QString s1 = "Eagle";
    QString s2 = "Eagle\n";
    QString s3 = "Eagle ";
    QString s4 = "орел";
    
    out << s1.length() << endl
        << s2.length() << endl
        << s3.length() << endl
        << s4.length() << endl;
    
    return 0;
}
