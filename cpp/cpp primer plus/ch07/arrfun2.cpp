// arrfun2.cpp -- functions with an array argument
#include <iostream>

const int AR_SIZE = 8;

int sum_arr(int[], int);

int main() {
    int cookies[AR_SIZE] = {1, 2, 4, 8, 16, 32, 64, 128};

    std::cout << cookies << " = array address, " << sizeof cookies << " = sizeof cookies\n";
    int sum = sum_arr(cookies, AR_SIZE);
    std::cout << "Total cookies eaten: " << sum << std::endl;
    sum = sum_arr(cookies, 3);
    std::cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies+4, 4);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n) {
    int total = 0;

    std::cout << arr << " = arr, " << sizeof arr << " = sizeof arr\n";

    for (int i = 0; i < n; ++i)
        total += arr[i];

    return total;
}
