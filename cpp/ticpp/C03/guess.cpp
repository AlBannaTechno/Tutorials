// C03: guess.cpp
// Guess a number (demonstrating while)
#include <iostream>
using namespace std;

int main()
{
	int secret = 15;
	int guess = 0;

	while (guess != secret) {
		cout << "Guess the number: ";
		cin >> guess;
	}

	cout << "You guessed it!" << endl;

	return 0;
}