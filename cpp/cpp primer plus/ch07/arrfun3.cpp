// arrfun3.cpp -- array functions and const
#include <iostream>

const int MAX = 5;

int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
void revalue(double r, double arr[], int n);

int main() {
    using namespace std;

    double properties[MAX];

    int size = fill_array(properties, MAX);
    show_array(properties, size);

    if (size > 0) {
        cout << "Enter revaluation factor: ";
        double factor;

        while (!(cin >> factor)) {  // bad input
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; please enter a number: ";
        }

        revalue(factor, properties, size);
        show_array(properties, size);
    }

    cout << "Done.\n";

    return 0;
}

int fill_array(double arr[], int limit) {
    using namespace std;

    double temp;
    int i;

    for (i = 0; i < limit; ++i) {
        cout << "Enter a value #" << (i+1) << ": ";
        cin >> temp;

        if (!cin) {  // bad input
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)  // signal to terminate
            break;

        arr[i] = temp;
    }

    return i;
}

// the following function can use, but not alter, the array whose address is arr
void show_array(const double arr[], int n) {
    using namespace std;

    for (int i = 0; i < n; ++i)
        cout << "Property #" << (i+1) << ": $" << arr[i] << endl;
}

// multiplies each array element of arr[] by r
void revalue(double r, double arr[], int n) {
    for (int i = 0; i < n; ++i)
        arr[i] *= r;
}
