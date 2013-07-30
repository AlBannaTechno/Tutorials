// formore.cpp -- more looping with for
#include <iostream>

const int AR_SIZE = 16;

int main() {
    long long factorials[AR_SIZE];

    factorials[1] = factorials[0] = 1LL;
    for (int i = 2; i < AR_SIZE; ++i)
        factorials[i] = i * factorials[i-1];
    for (int i = 0; i < AR_SIZE; ++i)
        std::cout << i << "! = " << factorials[i] << std::endl;

    return 0;
}
