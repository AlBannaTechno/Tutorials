// sumafile.cpp -- functions with an array argument
#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE = 60;

int main() {
    using namespace std;

    char file_name[SIZE];
    ifstream in_file;  // object for handling file input

    cout << "Enter name of data file: ";
    cin.getline(file_name, SIZE);
    in_file.open(file_name);  // associate in_file with a file
    if (!in_file.is_open()) {  // failed to open file
        cout << "Could not open the file " << file_name << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;  // number of items read

    in_file >> value;  // get first value
    while (in_file.good()) {  // while input good and not EOF
        ++count;  // one more item read
        sum += value;  // calculate running total
        in_file >> value;  // get next value
    }

    if (in_file.eof())
        cout << "End of file reached.\n";
    else if (in_file.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";
    else {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    in_file.close();

    return 0;
}
