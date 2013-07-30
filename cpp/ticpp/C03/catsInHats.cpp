// C03: catsInHats.cpp
// Simple demonstration of recursion
#include <iostream>
using namespace std;

void removeHat(char);

int main()
{
	removeHat('A');
}

void removeHat(char cat) 
{
	for (char c = 'A'; c < cat; c++)
		cout << " ";
	if (cat <= 'Z') {
		cout << "cat " << cat << endl;
		removeHat(cat + 1);
	} else
		cout << "VOOM!!" << endl;
}