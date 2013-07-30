// C03: passReference.cpp
#include <iostream>
using namespace std;

void f(int&);

int main() 
{
	int x = 47;

	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	f(x);
	cout << "x = " << x << endl;

	return 0;
}

void f(int& r)
{
	cout << "r = " << r << endl;
	cout << "&r = " << &r << endl;
	r = 5;
	cout << "r = " << r << endl;
}