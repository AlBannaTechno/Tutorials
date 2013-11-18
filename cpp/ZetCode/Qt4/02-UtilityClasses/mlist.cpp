#include <QtCore/QTextStream>
#include <QtCore/QList>


int main() {
    QTextStream out(stdout);
    QList<QString> list;

    list << "Balzac" << "Tolstoy" << "Guldbrassen" << "London" << "Galsworthy" << "Sienkiewicz";
    qSort(list);

    for (int i = 0; i < list.size(); ++i)
        out << list.at(i) << endl;
}
