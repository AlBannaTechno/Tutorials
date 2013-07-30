// twofile2.cpp -- variables with internal and external linkage, compile with twofile1.cpp
#include <iostream>


extern int tom;  // tom defined elseware
static int dick = 10;  // overrides external dick
int harry = 100;  // external variable definition, no conflict with twofile1 harry (due to static)


void remote_access() {
    using namespace std;
    cout << "remote_access() reports the following addresses:\n"
         << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry\n";
}
