// cubes.cpp -- regular and reference arguments
#include <iostream>

double cube(double a);
double refcube(double &a);

int main() {
    double x = 3.0;

    std::cout << cube(x) << " = cube of " << x << std::endl
              << refcube(x) << " = cube of " << x << std::endl;

    return 0;
}

double cube(double a) {
    a *= a * a;
    return a;
}

double refcube(double &ra) {
    ra *= ra * ra;
    return ra;
}
