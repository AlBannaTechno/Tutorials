#include "fraction.h"

int Fraction::Assigns = 0;
int Fraction::Copies = 0;
int Fraction::Ctors = 0;

Fraction::Fraction(int n, int d)
    : _numer(n), _denom(d)
{
    ++Ctors;
}

Fraction::Fraction(const Fraction &other)
    : _numer(other._numer), _denom(other._denom)
{
    ++Copies;
}

Fraction &Fraction::operator=(const Fraction &other)
{
    if (this != &other) {
        _numer = other._numer;
        _denom = other._denom;
        ++Assigns;
    }

    return *this;
}

Fraction Fraction::operator*(const Fraction &other) {
    return Fraction(_numer * other._numer, _denom * other._denom);
}

Fraction Fraction::multiply(Fraction other)
{
    return Fraction(_numer * other._numer, _denom * other._denom);
}

QString Fraction::Report()
{
    return QString(" [assigns: %1 copies: %2 ctors: %3]").arg(Assigns).arg(Copies).arg(Ctors);
}
