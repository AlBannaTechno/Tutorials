#include <iostream>

void foo(int n);
void foo(double x);
void foo(bool b);

int main() {
    foo(5);
    foo(6.7);
    foo(true);
}

void foo(int n) {
    std::cout << n << " is a nice int.\n";
}

void foo(double x) {
    std::cout << x << " is a nice double.\n";
}

void foo(bool b) {
    std::cout << "Always be " << (b ? "true" : "false") << " to your bool.\n";
}
