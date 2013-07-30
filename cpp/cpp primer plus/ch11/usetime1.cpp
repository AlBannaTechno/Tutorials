// usetime1.cpp -- using the second draft of the Time class
// compile usetime1.cpp and mytime1.cpp together
#include <iostream>
#include "mytime1.h"

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

    total = coding + fixing;  // operator notation
    std::cout << "coding + fixing = ";
    total.show();
    std::cout << std::endl;

    Time more_fixing(3, 28);
    std::cout << "more fixing time = ";
    more_fixing.show();
    std::cout << std::endl;
    total = more_fixing.operator+(total);  // function notation, messy
    std::cout << "more_fixing.operator+(total) = ";
    total.show();
    std::cout << std::endl;

    return 0;
}
