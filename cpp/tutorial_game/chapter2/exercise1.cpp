// Exercise 1
// Rewrite of Menu Chooser using Enumeration as difficulty levels

#include <iostream>

using namespace std;

int main()
{
	enum diff {EASY = 1, MEDIUM, HARD};
	int choice;

	cout << "\nChoose a Difficulty" << endl;
	cout << EASY << " - Easy" << endl;
	cout << MEDIUM << " - Medium" << endl;
	cout << HARD << " - Hard" << endl;
	cout << "Pick: ";

	cin >> choice;

	switch (choice)
	{
		case EASY:
			cout << "You picked Easy!";
			break;
		case MEDIUM:
			cout << "You picked Medium!";
			break;
		case HARD:
			cout << "You Picked Hard!";
			break;
		default:
			cout << "Unknown selection";
	}

	cout << endl;
	return 0;
}