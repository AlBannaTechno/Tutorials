#include <QtCore/QTextStream>


int main() {
    QString string = "The history of my life.";

    QTextStream out(stdout);
    out << "The string has " + QString::number(string.size()) + " characters." << endl;
}
