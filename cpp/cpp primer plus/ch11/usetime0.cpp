// usetime0.cpp -- using the first draft of the Time class
// compile usetime0.cpp and mytime0.cpp together
#include <iostream>
#include "mytime0.h"

int main() {
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    std::cout << "planning time = ";
    planning.show();
    std::cout << std::endl;

    std::cout << "coding time = ";
    coding.show();
    std::cout << std::endl;

    std::cout << "fixing time = ";
    fixing.show();
    std::cout << std::endl;

    total = coding.sum(fixing);
    std::cout << "coding.sum(fixing) = ";
    total.show();
    std::cout << std::endl;

    return 0;
}
