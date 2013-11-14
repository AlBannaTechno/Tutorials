// Basic output using Qt's QTextStream
#include <QtCore/QTextStream>


int main() {
    QTextStream out(stdout);
    out << "Console application\n";
}
