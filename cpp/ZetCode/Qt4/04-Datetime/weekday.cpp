#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>


int weekday() {
    QTextStream out(stdout);
    QDate cd = QDate::currentDate();
    int wd = cd.dayOfWeek();
    
    out << "Today is " << QDate::shortDayName(wd) << endl
        << "Today is " << QDate::longDayName(wd) << endl;
    
    return 0;
}
