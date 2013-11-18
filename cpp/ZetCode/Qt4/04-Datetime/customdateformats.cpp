#include "datetime.h"
#include <QtCore/QTextStream>
#include <QtCore/QDate>


int customdateformats() {
    QTextStream out(stdout);
    QDate cd = QDate::currentDate();
    
    out << "Today is " << cd.toString("yyyy-MM-dd") << endl
        << "Today is " << cd.toString("yy/M/dd") << endl
        << "Today is " << cd.toString("d.M.yyyy") << endl
        << "Today is " << cd.toString("d-MMMM-yyyy") << endl;
    
    return 0;
}
