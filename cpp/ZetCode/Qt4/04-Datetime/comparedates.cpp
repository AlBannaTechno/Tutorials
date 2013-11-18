#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>


int comparedates() {
    QTextStream out(stdout);
    
    QDate dt1(2012, 4, 5);
    QDate dt2(2011, 4, 5);
    
    if (dt1 < dt2)
        out << dt1.toString() << " comes before " << dt2.toString() << endl;
    else
        out << dt1.toString() << " comes after " << dt2.toString() << endl;
    
    return 0;
}
