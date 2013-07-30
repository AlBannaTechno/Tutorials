// exercise 4: menu.cpp
// altered menu.cpp to use switch statements instead
#include <iostream>
using namespace std;

int main() 
{
	char c;

	while (true) {
		cout << "MAIN MENU:" << endl;
		cout << "L: left, R: right, Q: quit -> ";
		cin >> c;

		if (c == 'Q')
			break;
		
		if (c == 'L') {
			cout << "LEFT MENU:" << endl;
			cout << "select a or b: ";
			cin >> c;

			if (c == 'a') {
				cout << "You chose 'a'" << endl;
				continue;
			}

			if (c == 'b') {
				cout << "You chose 'b'" << endl;
				continue;
			} else {
				cout << "You didn't choose a or b!" << endl;
				continue;
			}
		}

		if (c == 'R') {
			cout << "RIGHT MENU:" << endl;
			cout << "Select c or d: ";
			cin >> c;

			if (c == 'c') {
				cout << "You chose 'c'" << endl;
				continue;
			}

			if (c == 'd') {
				cout << "You chose 'd'" << endl;
				continue;
			} else {
				cout << "You didn't choose c or d!" << endl;
				continue;
			}
		}

		cout << "You must type L, R or Q!" << endl;
	}

	cout << "Quitting menu..." << endl;

	return 0;
}