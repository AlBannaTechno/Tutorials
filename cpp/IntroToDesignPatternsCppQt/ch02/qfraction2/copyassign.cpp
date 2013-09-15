#include <QtCore/QTextStream>
#include "fraction.h"

int main()
{
    QTextStream cout(stdout);

    Fraction two_thirds(2, 3);
    Fraction three_quarters(3, 4);
    Fraction acopy(two_thirds);
    Fraction f4 = three_quarters;

    cout << "After declarations: " << Fraction::Report() << endl;
    f4 = two_thirds;
    cout << "before multiply: " << Fraction::Report() << endl;
    f4 = two_thirds * three_quarters;
    cout << "after multiply: " << Fraction::Report() << endl;

    return 0;
}
