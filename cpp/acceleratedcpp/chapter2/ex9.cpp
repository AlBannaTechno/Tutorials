// Chapter 2 Exercise 9
// Write a program that asks the user to enter two numbers and tells the user which is larger 

#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	cout << "Enter a number: ";
	cin >> num1;
	cout << "Enter another number: ";
	cin >> num2;

	if (num1 > num2) 
		cout << num1 << " is greater then " << num2 << endl;
	else
		cout << num2 << " is greater then " << num1 << endl;

	return 0;
}