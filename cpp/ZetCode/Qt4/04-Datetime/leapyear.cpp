#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>


int leapyear() {
    QTextStream out(stdout);
    
    if (QDate::isLeapYear(2010)) 
        out << "2010 is a leap year" << endl;
    else
        out << "2010 is not a leap year" << endl;
    
    if (QDate::isLeapYear(2011)) 
        out << "2011 is a leap year" << endl;
    else
        out << "2011 is not a leap year" << endl;
    
    if (QDate::isLeapYear(2012)) 
        out << "2012 is a leap year" << endl;
    else
        out << "2012 is not a lear year" << endl;
    
    return 0;
}
