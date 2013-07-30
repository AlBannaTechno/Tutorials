// C03: menu2.cpp
// a menu using a switch statement
#include <iostream>
using namespace std;

int main()
{
	bool quit = false;

	while (quit == false) {
		cout << "Select a, b, c, or q to quit: ";
		char response;
		cin >> response;

		switch (response) {
			case 'a':
				cout << "You chose 'a'" << endl;
				break;
			case 'b':
				cout << "You chose 'b'" << endl;
				break;
			case 'c':
				cout << "You chose 'c'" << endl;
				break;
			case 'q':
				cout << "Quitting menu..." << endl;
				quit = true;
				break;
			default:
				cout << "Please use a, b, c, or q!" << endl;
		}
	}

	return 0;
}