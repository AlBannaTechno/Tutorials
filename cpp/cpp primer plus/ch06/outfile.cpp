// outfile.cpp -- writing to a file
#include <iostream>
#include <fstream>

int main() {
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream out_file;  // create object for output
    out_file.open("carinfo.txt");  // associate with a file

    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    // display information on screen with cout
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    // now do exact same things using out_file instead of cout
    out_file << fixed;
    out_file.precision(2);
    out_file.setf(ios_base::showpoint);
    out_file << "Make and model: " << automobile << endl;
    out_file << "Year: " << year << endl;
    out_file << "Was asking $" << a_price << endl;
    out_file << "Now asking $" << d_price << endl;
    out_file.close();  // done with file

    return 0;
}
