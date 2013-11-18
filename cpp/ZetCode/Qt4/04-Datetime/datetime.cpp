#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDateTime>


int datetime() {
    QTextStream out(stdout);
    QDateTime cdt = QDateTime::currentDateTime();
    
    out << "The current datetime is " << cdt.toString() << endl
        << "The current date is " << cdt.date().toString() << endl
        << "The current time is " << cdt.time().toString() << endl;
    
    return 0;
}
