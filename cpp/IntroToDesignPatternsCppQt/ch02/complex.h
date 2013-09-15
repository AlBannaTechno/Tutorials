#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <string>

class Complex {
public:
    Complex(double real_part, double im_part);
    Complex(double real_part);
    Complex();

    std::string toString() const;

private:
    double real, imaginary;
};

#endif
