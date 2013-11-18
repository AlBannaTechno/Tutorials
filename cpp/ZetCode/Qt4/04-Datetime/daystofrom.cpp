#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>


int daystofrom() {
    QTextStream out(stdout);
    QDate dt(2012, 5, 11);
    QDate nd = dt.addDays(55);
    QDate xmas(2013, 12, 24);
    
    out << "55 days from " << dt.toString() << " is " << nd.toString() << endl
        << "There are " << QDate::currentDate().daysTo(xmas) << " days till Christmas" << endl;
    
    return 0;
}
