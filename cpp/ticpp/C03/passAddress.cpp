// C03: passAddress.cpp
#include <iostream>
using namespace std;

void f(int*);

int main() 
{
	int x = 47;

	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	f(&x);
	cout << "x = " << x << endl;

	return 0;
}

void f(int* p) 
{
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;
	*p = 5;
	cout << "p = " << p << endl;
}