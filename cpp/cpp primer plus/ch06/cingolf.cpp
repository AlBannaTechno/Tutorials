// cingolf.cpp -- non-numeric input skipped
#include <iostream>

const int MAX = 5;

int main() {
    using namespace std;

    // get data
    int golf[MAX];
    cout << "Please enter your golf scores.\nYou must enter " << MAX << " rounds.\n";

    int i;
    for (i = 0; i < MAX; ++i) {
        cout << "Round #" << i+1 << ": ";
        while (!(cin >> golf[i])) {
            cin.clear();  // reset input
            while (cin.get() != '\n')
                continue;  // get rid of bad input
            cout << "Please enter a number: ";
        }
    }

    // calculate average
    double total = 0.0;
    for (i = 0; i < MAX; ++i)
        total += golf[i];
    // report results
    cout << total / MAX << " = average score " << MAX << " rounds\n";

    return 0;
}
