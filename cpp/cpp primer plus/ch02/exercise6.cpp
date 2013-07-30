// exercise6.cpp -- Write a program that has main() call a user-defined function that takes a
// distance in light years as an argument and then returns the distance in astronomical units. The
// program should request the light year value as input from the user and display the result.
// For reference, 1 light year = 63240 astronomical units
#include <iostream>

double conLightYearToAstroUnit(double);

int main() {
    using namespace std;

    double ly;

    cout << "Enter the number of light years: ";
    cin >> ly;
    cout << ly << " light years = " << conLightYearToAstroUnit(ly) << " astronomical units."
         << endl;

    return 0;
}

double conLightYearToAstroUnit(double ly) {
    return ly * 63240;
}
