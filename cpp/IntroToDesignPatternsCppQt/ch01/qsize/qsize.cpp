#include <QString>
#include <QTextStream>
#include <QChar>
#include <QDate>

int main() {
    QTextStream cout(stdout);

    int i = 0;
    char array1[34] = "This is a dreaded C array of char";
    char array2[] = "if not for main, we could avoid it entirely.";
    char *charp = array1;
    QString qstring = "This is a unicode QString. Much preferred.";

    Q_ASSERT (sizeof(i) == sizeof(int));

    cout << "  c type sizes: \n";
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(double *) = " << sizeof(double *) << endl;
    cout << "sizeof(array1) = " << sizeof(array1) << endl;
    cout << "sizeof(array2) = " << sizeof(array2) << endl;
    cout << "sizeof(char *) = " << sizeof(charp) << endl;

    cout << "  qt type sizes: \n";
    cout << "sizeof(QString) = " << sizeof(QString) << endl;
    cout << "sizeof(qint32) = " << sizeof(qint32) << endl;
    cout << "sizeof(qint64) = " << sizeof(qint64) << endl;
    cout << "sizeof(QChar) = " << sizeof(QChar) << endl;
    cout << "sizeof(QDate) = " << sizeof(QDate) << endl;
    cout << "qstring.length() = " << qstring.length() << endl;

    return 0;
}
