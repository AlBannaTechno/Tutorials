#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>


int nofdays() {
    QTextStream out(stdout);
    QDate dt1(2012, 9, 18);
    QDate dt2(2012, 2, 11);
    QDate dt3(2012, 5, 1);
    QDate dt4(2012, 12, 11);
    QDate dt5(2012, 1, 21);
    
    out << "There are " << dt1.daysInMonth() << " days in " << QDate::longMonthName(dt1.month())
        << endl;
    out << "There are " << dt2.daysInMonth() << " days in " << QDate::longMonthName(dt2.month()) 
        << endl;
    out << "There are " << dt3.daysInMonth() << " days in " << QDate::longMonthName(dt3.month())
        << endl;
    out << "There are " << dt4.daysInMonth() << " days in " << QDate::longMonthName(dt4.month())
        << endl;
    out << "There are " << dt5.daysInMonth() << " days in " << QDate::longMonthName(dt5.month())
        << endl;
    
    out << "There are " << dt1.daysInYear() << " days in " << QString::number(dt1.year()) << endl;
    
    return 0;
}
