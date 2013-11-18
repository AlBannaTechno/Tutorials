#include <QtCore/QTextStream>
#include <QtCore/QTime>


int main() {
    QTextStream out(stdout);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString(Qt::LocalDate);

    out << stime << endl;
}
