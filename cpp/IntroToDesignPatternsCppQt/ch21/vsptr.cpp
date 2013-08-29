#include <iostream>

int main() {
    int a[] = {12, 34, 56, 78};
    std::cout << a << '\t' << &a[1] - a << std::endl;
    int x = 99;
//  a = &x'
    int *pa;
    std::cout << pa << std::endl;
    pa = &x;
    std::cout << pa << '\t' << pa - &a[3] << std::endl;
    std::cout << a[4] << '\t' << a[5] << std::endl;
    std::cout << *(a + 2) << '\t' << sizeof(int) << std::endl;
    void *pv = a;
    std::cout << pv << std::endl;
    int *pi = static_cast<int *>(pv);
    std::cout << *(pi + 2) << std::endl;

    return 0;
}
