// exercise4.cpp -- Write a program that asks the user to enter his/her age. The program then should
// display the age in months.
#include <iostream>

int main() {
    using namespace std;

    int age;

    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age in months is " << age * 12 << "." << endl;

    return 0;
}
