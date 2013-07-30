// structure.cpp -- a simple structure
#include <iostream>

struct inflatable {  // structure declaration
    char name[20];
    float volute;
    double price;
};

int main() {
    using namespace std;

    inflatable guest = {"Glorious Gloria", 1.88, 29.99};
    // guest is a structure variable of type inflatable. It's initialized to the indicated variables
    inflatable pal = {"Audacious Arthur", 3.12, 32.99};
    // pa1 is a second variable of type inflatable.

    cout << "Expand your guest list with " << guest.name << " and " << pal.name << "!\n";
    cout << "You can have both for $" << guest.price + pal.price << "!\n";

    return 0;
}
