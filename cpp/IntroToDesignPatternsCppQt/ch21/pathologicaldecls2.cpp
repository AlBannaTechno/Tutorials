/* more ways to initialize pointers and examples of pointer issues */
#include <iostream>

int main() {
    int myint = 5;
    int *ptr1 = &myint;
    std::cout << "*ptr1 = " << *ptr1 << std::endl;
    int anotherint = 6;
//  *ptr1 = &anotherint;  // error: invalid conversion from int* to int

    int *ptr2;  // uninitialized pointer
    std::cout << "*ptr2 = " << *ptr2 << std::endl;
    *ptr2 = anotherint;  // unpredictable results

    int yetanotherint = 7;
    int *ptr3;
    ptr3 = &yetanotherint;  // regular assignment
    std::cout << "*ptr3 = " << *ptr3 << std::endl;
    *ptr1 = *ptr2;  // dangerous assignment
    std::cout << "*ptr1 = " << *ptr1 << std::endl;

    return 0;
}
