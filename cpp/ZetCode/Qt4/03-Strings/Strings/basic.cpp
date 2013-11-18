#include "strings.h"
#include <QtCore/QTextStream>


int basic() {
    QTextStream out(stdout);
    QString a = "love";
    
    a.append(" chess");
    a.prepend("I ");
    
    out << a << endl
        << "The a string has " << a.count() << " characters" << endl
        << a.toUpper() << endl
        << a.toLower() << endl;
    
    return 0;
}