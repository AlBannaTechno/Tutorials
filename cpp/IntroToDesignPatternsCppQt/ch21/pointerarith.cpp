#include <iostream>

int main() {
    int y[] = {3, 6, 9};
    int x = 12;
    int *px;
    px = y;

    std::cout << "What's next: " << *++px << std::endl;
    std::cout << "What's next: " << *++px << std::endl;
    std::cout << "What's next: " << *++px << std::endl;
    std::cout << "What's next: " << *++px << std::endl;

    return 0;
}
