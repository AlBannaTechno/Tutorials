#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDateTime>


int utclocal() {
    QTextStream out(stdout);
    QDateTime cdt = QDateTime::currentDateTime();
    
    out << "Universal datetime " << cdt.toUTC().toString() << endl
        << "Local datetime " << cdt.toLocalTime().toString() << endl;
    
    return 0;
}
