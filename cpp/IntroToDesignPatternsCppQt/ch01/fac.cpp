/* Computes and prints n! for given n.
   Uses several basic elements of C++. */
#include <iostream>

int main() {
    int factArg = 0;
    int fact = 1;

    do {
        std::cout << "Factorial of: ";
        std::cin >> factArg;

        if (factArg < 0)
            std::cout << "No negative values, please!\n";
    }
    while (factArg < 0);

    int i = 2;
    while (i <= factArg) {
        fact *= i;
        i += 1;
    }

    std::cout << "The Factorial of " << factArg << " is: " << fact << std::endl;

    return 0;
}
