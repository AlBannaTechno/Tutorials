// enum.cpp -- using enum
#include <iostream>

enum {RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, INDIGO};

int main() {
    using namespace std;
    cout << "Enter color code (0-6):";
    int code;
    cin >> code;
    while (code >= RED && code <= INDIGO) {
        switch (code) {
            case RED:  cout << "Her lips were red.\n"; break;
            case ORANGE:  cout << "Her hair was orange.\n"; break;
            case YELLOW:  cout << "Her shoes were yellow.\n"; break;
            case GREEN:  cout << "Her nails were green.\n"; break;
            case BLUE:  cout << "Her sweatsuit was blue.\n"; break;
            case VIOLET:  cout << "Her eyes were violet.\n"; break;
            case INDIGO:  cout << "Her mood was indigo.\n"; break;
        }
        cout << "Enter a color code (0-6): ";
        cin >> code;
    }
    cout << "Bye!\n";

    return 0;
}
