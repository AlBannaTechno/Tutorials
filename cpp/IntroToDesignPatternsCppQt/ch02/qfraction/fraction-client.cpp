#include <QTextStream>
#include "fraction.h"

int main() {
    const int DASHES = 30;
    QTextStream cout(stdout);

    {
        int i;
        for (i = 0; i < DASHES; ++i)
            cout << "=";
        cout << endl;
    }

//  cout << "i = " << i << endl;  // this will error out, i does not exist in this scope
    Fraction f1, f2;
    f1.set(3, 4);
    f2.set(11, 12);
//  f2.m_numerator = 12;  // this will error out, as m_numerator is private
    cout << "The first fraction is: " << f1.toString() << endl;
    cout << "\nThe second fraction, expressed as a double is: " << f2.toDouble() << endl;

    return 0;
}
