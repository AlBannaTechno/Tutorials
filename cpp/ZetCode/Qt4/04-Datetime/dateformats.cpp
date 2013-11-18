#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>


int dateformats() {
    QTextStream out(stdout);
    QDate cd = QDate::currentDate();
    
    out << "Today is " << cd.toString(Qt::TextDate) << endl
        << "Today is " << cd.toString(Qt::ISODate) << endl
        << "Today is " << cd.toString(Qt::SystemLocaleShortDate) << endl
        << "Today is " << cd.toString(Qt::SystemLocaleLongDate) << endl
        << "Today is " << cd.toString(Qt::DefaultLocaleShortDate) << endl
        << "Today is " << cd.toString(Qt::DefaultLocaleLongDate) << endl
        << "Today is " << cd.toString(Qt::SystemLocaleDate) << endl
        << "Today is " << cd.toString(Qt::LocaleDate) << endl;
    
    return 0;
}
