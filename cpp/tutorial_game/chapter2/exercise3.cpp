// Exercise 3
// Reversal of Guess My Number

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));

	int num = 0, tries = 0, guess = 0;
		
	while (true)
	{	
		cout << "\nPick a number for the computer to guess between 1 and 100" << endl;
		cout << "Number: ";
		cin >> num;

		if (0 < num < 101)
			break;
	} 

	cout << "Computer guesses ";

	do 
	{
		cout << (guess = (rand() % 100 + 1)) << " ";
		++tries;
	} while (guess != num);
	
	cout << "\nand guessed correctly after " << tries << " guesses!" << endl;	

	return 0;
}