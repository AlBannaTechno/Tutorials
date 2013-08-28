#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "== Random Number Generator =="
              << "\n\nThis program will take a seed number and output 10 random numbers!\n";

    int seed = 0;
    std::cout << "Please enter a seed number: ";
    std::cin >> seed;

    std::cout << "Generating a random seed...\n";
    std::srand(seed);
    std::cout << "Outputting random numbers...\n";
    for (int i = 0; i < 10; ++i)
        std::cout << i << " = " << std::rand() << std::endl;

    std::cout << "Done!\n";

    return EXIT_SUCCESS;
}
