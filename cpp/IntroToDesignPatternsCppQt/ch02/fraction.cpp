class Fraction
{
public:
    Fraction(int n)
        : _numer(n), _denom(1) { }
    Fraction(int n, int d)
        : _numer(n), _denom(d) { }
    Fraction times(const Fraction &other)
    { return Fraction(_numer * other._numer, _denom * other._denom); }

private:
    int _numer;
    int _denom;
};

int main()
{
    int i;
    Fraction frac(8);
    Fraction frac2 = 5;

    frac = 9;
    frac = (Fraction) 7;
    frac = Fraction(6);
    frac = static_cast<Fraction>(6);
    frac = frac2.times(19);

    return 0;
}
