#include "strings.h"
#include <QtCore/QTextStream>


int substrings() {
    QTextStream out(stdout);
    QString str = "The night train";
    
    out << str.right(5) << endl
        << str.left(9) << endl
        << str.mid(4, 5) << endl;
    
    QString str2("The big apple");
    QStringRef sub(&str2, 0, 7);
    
    out << sub.toString() << endl;
    
    return 0;
}
