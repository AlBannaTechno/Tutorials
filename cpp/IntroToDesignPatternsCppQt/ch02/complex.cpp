#include "complex.h"
#include <iostream>
#include <sstream>

Complex::Complex(double real_part, double im_part)
    : real(real_part), imaginary(im_part)
{
    std::cout << "complex(" << real << "," << imaginary << ")\n";
}

Complex::Complex(double real_part)
    : real(real_part), imaginary(0.0)
{ }

Complex::Complex()
    : real(0.0), imaginary(0.0)
{ }

std::string Complex::toString() const {
    std::ostringstream strbuf;
    strbuf << '(' << real << ", " << imaginary << ')';
    return strbuf.str();
}

int main() {
    Complex C1;
    Complex C2(3.14);
    Complex C3(6.2, 10.23);

    std::cout << C1.toString() << ' ' << C2.toString() << ' ' << C3.toString() << std::endl;

    return 0;
}
