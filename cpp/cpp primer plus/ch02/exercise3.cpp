// exercise3.cpp -- write a program that uses three user-defined functions (counting main() as one)
// and produces the following output:
// Three blind mice
// Three blind mice
// See how they run
// See how they run
// One function called two times should produce the first two lines, and the remaining function,
// also called twice, should produce the remaining output.
#include <iostream>

using namespace std;

void blindMice(void);
void sawRunning(void);

int main() {
    blindMice();
    blindMice();
    sawRunning();
    sawRunning();

    return 0;
}

void blindMice() {
    cout << "Three blind mice" << endl;
}

void sawRunning() {
    cout << "See how they run" << endl;
}
