// exercise5.cpp -- Write a program that has a main() call a user-defined function that takes a
// Celsius temperature value as an argument and then returns the equivalent Fahrenheit value. The
// program should request the Celsius value as input from the user and display the result.
// For reference, here is the formula for making the conversion: F = 1.8 * C + 32.0
#include <iostream>

double conCelsiusToFahrenheit(double);

int main() {
    using namespace std;

    double celsius;

    cout << "Please enter a Celsius value: ";
    cin >> celsius;
    cout << celsius << " degrees Celsius is " << conCelsiusToFahrenheit(celsius)
         << " degrees Fahrenheit." << endl;

    return 0;
}

double conCelsiusToFahrenheit(double c) {
    return (1.8 * c + 32.0);
}
