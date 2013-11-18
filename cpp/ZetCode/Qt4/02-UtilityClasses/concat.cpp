#include <QtCore/QTextStream>


int main() {
    QString a = "Disziplin";
    QString b = "ist ";
    QString c = "Macht.\n";

    QTextStream out(stdout);
    out << a + b + c;
}
