#include "fraction.h"

Fraction::Fraction()
    : _numerator(0), _denominator(0)
{ }

Fraction::Fraction(int numer, int denom)
    : _numerator(numer), _denominator(denom)
{ }

void Fraction::set(int numer, int denom)
{
    _numerator = numer;
    _denominator = denom;
}

QString Fraction::toString() const
{
    return QString("%1 / %2").arg(_numerator).arg(_denominator);
}

double Fraction::toDouble() const
{
    return 1.0 * _numerator / _denominator;
}

Fraction &Fraction::operator=(const Fraction &other)
{
    if (this != &other) {
        _numerator = other._numerator;
        _denominator = other._denominator;
    }

    return *this;
}

Fraction Fraction::operator+(const Fraction &other)
{
    return Fraction((_numerator * other._denominator) + (other._numerator * _denominator),
                    _denominator * other._denominator);
}

Fraction Fraction::operator-(const Fraction &other)
{
    return Fraction((_numerator * other._denominator) - (other._numerator * _denominator),
                    _denominator * other._denominator);
}

Fraction Fraction::operator*(const Fraction &other)
{
    return Fraction(_numerator * other._numerator, _denominator * other._denominator);
}

Fraction Fraction::operator/(const Fraction &other)
{
    return Fraction(_numerator * other._denominator, _denominator * other._numerator);
}
