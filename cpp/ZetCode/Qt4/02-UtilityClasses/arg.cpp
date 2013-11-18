#include <QtCore/QTextStream>


int main() {
    QString string = "What if I give you %1 red roses?";
    int num = 21;

    QTextStream out(stdout);
    out << string.arg(num) << endl;
}
