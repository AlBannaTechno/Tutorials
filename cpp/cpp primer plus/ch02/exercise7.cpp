// exercise7.cpp -- Write a program that asks the user to enter an hour value and a minute value.
// The main() function should then pass these two values to a type void function that displays the
// two values in standard time format.
#include <iostream>

using namespace std;

void displayTime(int, int);

int main() {
    int hour, min;

    cout << "Enter the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> min;
    displayTime(hour, min);

    return 0;
}

void displayTime(int h, int m) {
    cout << "Time: " << h << ":" << m << endl;
}
