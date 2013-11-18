#include "strings.h"
#include <QtCore/QTextStream>


int access() {
    QTextStream out(stdout);
    QString a = "Eagle";
    
    out << a[0] << endl;
    out << a[4] << endl;
    out << a.at(0) << endl;
    
    // QString.at will return an assert error if index given isn't valid
//    if (a.at(5).isNull()) 
//        out << "Outside the range of the string" << endl;
    
    return 0;
}
