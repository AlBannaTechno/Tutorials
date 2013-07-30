// twotemps.cpp -- using overloaded template functions
#include <iostream>


// constants
const int AR_SIZE = 8;


// templates
template <typename T>
void swap(T &a, T &b);
template <typename T>
void swap(T *a, T *b, int n);


// prototypes
void show(int a[]);


int main() {
    int i = 10, j = 20;
    std::cout << "i, j = " << i << ", " << j << ".\n";
    std::cout << "Using compiler-generated int swapper:\n";
    swap(i, j);  // matches original template
    std::cout << "Now i, j = " << i << ", " << j << ".\n";

    int d1[AR_SIZE] = {0, 7, 0, 4, 1, 7, 7 ,6};
    int d2[AR_SIZE] = {0, 7, 2, 0, 1, 9, 6, 9};
    std::cout << "Original arrays:\n";
    show(d1);
    show(d2);
    swap(d1, d2, AR_SIZE);  // matches new template
    std::cout << "Swapped arrays:\n";
    show(d1);
    show(d2);

    return 0;
}

template <typename T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void swap(T a[], T b[], int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void show(int a[]) {
    std::cout << a[0] << a[1] << "/" << a[2] << a[3] << "/";
    for (int i = 4; i < AR_SIZE; i++)
        std::cout << a[i];
    std::cout << std::endl;
}
