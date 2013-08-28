#include <iostream>

void foo(int n);

int main() {
    std::cout << "before call: " << 5 << std::endl;
    foo(5);
    std::cout << "before call: " << 6.7 << std::endl;
    foo(6.7);
    std::cout << "before call: " << true << std::endl;
    foo(true);

    return 0;
}

void foo(int n) {
    std::cout << n << " is a nice number.\n";
}
