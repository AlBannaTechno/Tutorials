#include <QtCore/QTextStream>
#include <QtCore/QDir>


int main() {
    QTextStream out(stdout);
    QString home = QDir::homePath();
    out << home << endl;
}
