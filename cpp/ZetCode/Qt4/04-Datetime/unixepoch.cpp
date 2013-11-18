#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDateTime>
#include <ctime>


int unixepoch() {
    QTextStream out(stdout);
    
    time_t t = time(0);
    out << t << endl;
    
    QDateTime dt;
    dt.setTime_t(t);
    out << dt.toString() << endl;
    
    QDateTime cd = QDateTime::currentDateTime();
    out << cd.toTime_t() << endl;
    
    return 0;
}
