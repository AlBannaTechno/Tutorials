#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>


int isvalid() {
    QTextStream out(stdout);
    QDate dt1(2012, 5, 11);
    QDate dt2(2012, 8, 1);
    QDate dt3(2012, 2, 30);
    
    if (dt1.isValid()) 
        out << "The first date is valid" << endl;
    else
        out << "The first date is not valid" << endl;
    
    if (dt2.isValid()) 
        out << "The second date is valid" << endl;
    else
        out << "The second date is not valid" << endl;
    
    if (dt3.isValid()) 
        out << "The third date is valid" << endl;
    else 
        out << "The third date is not valid" << endl;
    
    return 0;
}
