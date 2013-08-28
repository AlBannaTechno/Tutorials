#include <iostream>

int main() {
    int *p_i = 0;
    delete p_i;

    if (p_i) std::cout << "non-null" << std::endl;
    else std::cout << "null" << std::endl;

    p_i = new int;
    int *p_j = new int(13);

    std::cout << "*p_i = " << *p_i << " *p_j = " << *p_j << std::endl;

    *p_i = *p_j + 27;

    if (p_i) std::cout << "non-null" << std::endl;
    else std::cout << "null" << std::endl;

    std::cout << "*p_i = " << *p_i << " *p_j = " << *p_j << std::endl;

    delete p_i;
    delete p_j;
}
