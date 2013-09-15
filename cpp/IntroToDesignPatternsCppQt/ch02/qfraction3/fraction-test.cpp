#include "fraction.h"
#include <QtCore/QTextStream>

int main()
{
    QTextStream cout(stdout);

    Fraction f1;
    Fraction f2(2, 3);
    Fraction f3(5, 4);
    Fraction f4(2, 5);

    cout << "Values before modification: " << endl
         << "f1: " << f1.toString() << endl
         << "f2: " << f2.toString() << endl
         << "f3: " << f3.toString() << endl
         << "f4: " << f4.toString() << endl << endl;

    f1 = f2;
    f2.set(6, 10);
    f4 = f2 * f3;

    cout << "f1: " << f1.toString() << endl
         << "f2: " << f2.toString() << endl
         << "f3: " << f3.toString() << endl
         << "f4: " << f4.toString() << endl << endl
         << "f1 as double: " << f1.toDouble() << endl
         << "f4 as double: " << f4.toDouble() << endl << endl
         << "f2 * f3 = " << (f2 * f3).toString() << endl
         << "f1 - f4 = " << (f1 - f4).toString() << endl
         << "f4 + f3 = " << (f4 + f3).toString() << endl
         << "f3 / f1 = " << (f3 / f1).toString() << endl;

    return EXIT_SUCCESS;
}
