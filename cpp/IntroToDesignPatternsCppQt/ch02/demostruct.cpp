#include <iostream>
#include "demostruct.h"

void printFraction(fraction f);

int main() {
    fraction f1;
    fraction f2 = {2, 3, "two thirds"};

    f1.numer = 4;
    f1.denom = 5;
    f1.description = "four fifths";

    f1.numer += 2;
    printFraction(f1);
    printFraction(f2);

    return 0;
}

void printFraction(fraction f) {
    std::cout << f.numer << "/" << f.denom << std::endl;
    std::cout << "  =? " << f.description << std::endl;
}
