// exercise1.cpp -- write a short program that asks for your height in integer inches and then
// converts your height to feet in inches. Have the program use the underscore character to indicate
// where to type the response. Also use a const symbolic constant to represent the conversion factor
#include <iostream>

int main() {
    using namespace std;

    const int IN_PER_FOOT = 12;
    int height;

    cout << "Enter your height in inches: ___\b\b\b";
    cin >> height;
    int feet = height / IN_PER_FOOT;
    int inch = height % IN_PER_FOOT;
    cout << "You are " << feet << " feet and " << inch << " inches tall." << endl;

    return 0;
}
