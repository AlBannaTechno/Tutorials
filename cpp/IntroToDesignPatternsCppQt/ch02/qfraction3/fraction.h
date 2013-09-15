#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <QtCore/QString>

class Fraction
{
public:
    Fraction();
    Fraction(int numer, int denom);

    void set(int numer, int denom);
    QString toString() const;
    double toDouble() const;
    Fraction &operator=(const Fraction &other);
    Fraction operator+(const Fraction &other);
    Fraction operator-(const Fraction &other);
    Fraction operator*(const Fraction &other);
    Fraction operator/(const Fraction &other);

private:
    int _numerator;
    int _denominator;
};

#endif
