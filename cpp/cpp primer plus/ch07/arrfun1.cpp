// arrfun1.cpp -- functions with an array argument
#include <iostream>

const int AR_SIZE = 8;

int sum_arr(int[], int);
// can be coded as int sum_arr(int*, int); also, but array notation is preferred

int main() {
    using namespace std;

    int cookies[AR_SIZE] = {1, 2, 4, 8, 16, 32, 64, 128};
    int sum = sum_arr(cookies, AR_SIZE);

    cout << "Total cookies eaten: " << sum << ".\n";

    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n) {
    int total = 0;

    for (int i = 0; i < n; ++i)
        total += arr[i];

    return total;
}
