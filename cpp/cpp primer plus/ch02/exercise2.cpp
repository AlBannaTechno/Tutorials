// exercise2.cpp -- Write a program that asks for a distance in furlongs and converts it to yards.
#include <iostream>

double conFurlongToYard(double);

int main() {
    using namespace std;

    double furlong;

    cout << "Hello! This program converts Furlongs to yards!" << endl;
    cout << "Please enter a value in furlongs: ";
    cin >> furlong;
    cout << "That comes to " << conFurlongToYard(furlong) << " yards!" << endl;

    return 0;
}

double conFurlongToYard(double furlong) {
    return furlong * 220;
}
