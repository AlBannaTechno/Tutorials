#include <iostream>
#include <string>

int main() {
    const int THIS_YEAR = 2013;
    std::string your_name;
    int birth_year;

    std::cout << "What is your name? " << std::flush;
    std::getline(std::cin, your_name);

    std::cout << "What year were you born? ";
    std::cin >> birth_year;

    std::cout << "Your name is " << your_name << " and you are approximately "
              << (THIS_YEAR - birth_year) << " years old. \n";

    return 0;
}
