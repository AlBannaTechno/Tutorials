// Game Over
// A first C++ program

#include <iostream>

int main()
{
    std::cout << "Game Over!" << std::endl;
    std::cout << "Press the enter key to exit";
    std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
    return 0;
}

