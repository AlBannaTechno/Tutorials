#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <QtCore/QString>

class Fraction
{
public:
    Fraction(int n, int d);
    Fraction(const Fraction &other);
    Fraction &operator=(const Fraction &other);
    Fraction operator*(const Fraction &other);
    Fraction multiply(const Fraction other);
    static QString Report();

private:
    int _numer;
    int _denom;
    static int Assigns;
    static int Copies;
    static int Ctors;
};

#endif
