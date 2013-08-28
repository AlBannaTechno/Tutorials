#include <iostream>
#include <stdexcept>
#include <string>

double factorial(double n);

int main() {
    double n = 0;
    std::string input;

    std::cout << "Please enter n: ";
    std::cin >> input;

    while (true) {
        try {
            n = std::stod(input, 0);

            if (n == 9999)
                break;

            if (n > 0)
                std::cout << "factorial(" << n << ") = " << factorial(n) << std::endl;
            else
                std::cerr << "Undefined: factorial of a negative number: " << n << std::endl;
        }
        catch (std::invalid_argument &e) {
            std::cerr << "Error: non-numeric character given: " << input << std::endl;
        }

        std::cout << "Please enter n: ";
        std::cin >> input;
    }

    return 0;
}

double factorial(double n) {
    double ans = 1;

    for (double i = 2; i <= n; ++i) {
        ans *= i;
        if (ans < 0)
            return -1;
    }

    return ans;
}
