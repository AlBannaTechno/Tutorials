#include "strings.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>
#include <QtCore/QTime>


int curdatetime() {
    QTextStream out(stdout);
    
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    
    out << "Current date is " << cd.toString() << endl
        << "Current time is " << ct.toString() << endl;
    
    return 0;
}
