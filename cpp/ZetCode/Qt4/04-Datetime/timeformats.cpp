#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QTime>


int timeformats() {
    QTextStream out(stdout);
    QTime ct = QTime::currentTime();
    
    out << "The time is " << ct.toString(Qt::TextDate) << endl
        << "The time is " << ct.toString(Qt::ISODate) << endl
        << "The time is " << ct.toString(Qt::SystemLocaleShortDate) << endl
        << "The time is " << ct.toString(Qt::SystemLocaleLongDate) << endl
        << "The time is " << ct.toString(Qt::DefaultLocaleShortDate) << endl
        << "The time is " << ct.toString(Qt::DefaultLocaleLongDate) << endl
        << "The time is " << ct.toString(Qt::SystemLocaleDate) << endl
        << "The time is " << ct.toString(Qt::LocaleDate) << endl;
    
    return 0;
}
