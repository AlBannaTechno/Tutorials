// protos.cpp -- using prototypes and function calls
#include <iostream>

void cheers(int);  // prototype: no return value
double cube(double);  // prototype: returns a double

int main() {
    using namespace std;

    cheers(5);  // function call
    cout << "Give me a number: ";
    double side;
    cin >> side;
    double volume = cube(side);  // function call
    cout << "A " << side << "-foot cube has a volume of " << volume << " cubic feet.\n";
    cheers(cube(2));  // prototype protection at work

    return 0;
}

void cheers(int n) {
    for (int i = 0; i < n; ++i)
        std::cout << "Cheers! ";
    std::cout << std::endl;
}

double cube(double x) {
    return x * x * x;
}
