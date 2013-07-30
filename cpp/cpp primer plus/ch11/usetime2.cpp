// usetime2.cpp -- using the third draft of the Time class
// compile usetime2.cpp and mytime2.cpp together
#include <iostream>
#include "mytime2.h"

int main() {
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    std::cout << "weeding time = ";
    weeding.show();
    std::cout << std::endl;

    std::cout << "waxing time = ";
    waxing.show();
    std::cout << std::endl;

    std::cout << "total work time = ";
    total = weeding + waxing;  // use operator+()
    total.show();
    std::cout << std::endl;

    std::cout << "weeding time - waxing time = ";
    diff = weeding - waxing;  // use operator-()
    diff.show();
    std::cout << std::endl;

    std::cout << "adjusted work time = ";
    adjusted = total * 1.5;  // use operator*()
    adjusted.show();
    std::cout << std::endl;

    return 0;
}
