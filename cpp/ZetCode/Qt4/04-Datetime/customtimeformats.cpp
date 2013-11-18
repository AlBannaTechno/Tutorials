#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QTime>


int customtimeformats() {
    QTextStream out(stdout);
    QTime ct = QTime::currentTime();
    
    out << "The time is " << ct.toString("hh:mm:ss.zzz") << endl
        << "The time is " << ct.toString("h:m:s a") << endl
        << "The time is " << ct.toString("H:m:s A") << endl
        << "The time is " << ct.toString("h:m AP") << endl; 
    
    return 0;
}
