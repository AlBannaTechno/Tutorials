// exceed.cpp -- exceeding some integers limits
#include <iostream>
#define ZERO 0  // makes ZERO symbol for 0 value
#include <climits>  // defines INT_MAX as largest int value

int main() {
    using namespace std;

    short sam = SHRT_MAX;  // initialize a variable to max value
    unsigned short sue = sam;  // ok if variable sam is already defined

    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited. " << endl
         << "Add $1 to each account." << endl << "Now ";
    sam += 1;
    sue += 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited.\nPoor Sam!"
         << endl;
    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl
         << "Take $1 from each account." << endl << "Now ";
    sam -= 1;
    sue -= 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl
         << "Lucky Sue!" << endl;

    return 0;
}
