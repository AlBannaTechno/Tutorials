#include <iostream>

int main() {
    int a[] = {10, 11, 12, 13, 14, 15};

    int *b = a + 1;
    std::cout << "a[3] = " << a[3] << std::endl
              << "b[3] = " << b[3] << std::endl;

    // it gets even worse.
    int c = 123;
    int *d = &c;
    std::cout << "d[0] = " << d[0] << std::endl
              << "d[1] = " << d[1] << std::endl
              << "d[2] = " << d[2] << std::endl;

    return 0;
}
