// C03: guess2.cpp
// guess program using a do-while loop
#include <iostream>
using namespace std;

int main()
{
	int secret = 15;
	int guess;

	do {
		cout << "Guess the number: ";
		cin >> guess;
	} while (guess != secret);

	cout << "You got it!" << endl;

	return 0;
}