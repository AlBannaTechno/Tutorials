#include <iostream>

long factorial(long num)
{
    long ans = 1;
    for (long i = 2; i <= num; ++i) {
        ans *= i;
        if (ans < 0) {
            return -1;
        }
    }
    return ans;
}


int main() {
    using namespace std;

    cout << "Please enter n: " << flush;
    long num;
    cin >> num;

    if (num >= 0) {
        long nfact = factorial(num);
        if (nfact < 0) {
            cerr << "overflow error: " << num << " is too big." << endl;
        }
        else {
            cout << "factorial(" << num << ") = " << nfact << endl;
        }
    }
    else {
        cerr << "Undefined: factorial of a negative number: " << num << endl;
    }

    return 0;
}
