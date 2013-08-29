#include <iostream>

int main() {
    int x = 23;
    int y = 45;
    int *px = &x;

    std::cout << "px[0] = " << px[0] << std::endl;
    std::cout << "px[1] = " << px[1] << std::endl;
    std::cout << "px[2] = " << px[2] << std::endl;
    std::cout << "px[-1] = " << px[-1] << std::endl;

    return 0;
}
