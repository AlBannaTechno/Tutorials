// C03: union.cpp
// the size and simple use of a union
#include <iostream>
using namespace std;

union Packed // declaration similar to a class
{
	char i;
	short j;
	int k;
	long l;
	float f;
	double d;
	// the union will be the size of a double, since that's the largest element
}; // semicolon ends a union, like a struct

int main()
{
	cout << "sizeof(Packed) = " << sizeof(Packed) << endl;
	Packed x;
	x.i = 'c';
	cout << x.i << endl;
	x.d = 3.13159;
	cout << x.d << endl;

	return 0;
}