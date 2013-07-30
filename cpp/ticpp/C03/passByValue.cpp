// C03: passByValue.cpp
#include <iostream>
using namespace std;

void f(int);

int main()
{
	int x = 47;

	cout << "x = " << x << endl;
	f(x);
	cout << "x = " << x << endl;

	return 0;
}

void f(int a)
{
	cout << "a = " << a << endl;
	a = 5;
	cout << "a = " << a << endl;
}