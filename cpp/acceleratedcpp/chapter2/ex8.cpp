// Chapter 2 Exercise 8
// write a program to generate the product of the numbers in the range 1 to 10

#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	for (int i = 1; i != 11; ++i) 
		sum += i;
	cout << sum << endl;
	return 0;
}