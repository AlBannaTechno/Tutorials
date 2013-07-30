// C03: pointerIncremonet2.cpp
#include <iostream>
using namespace std;

typedef struct 
{
	char c;
	short s;
	int i;
	long l;
	double f;
	long double ld;
} Primitives;

int main()
{
	Primitives p[10];
	Primitives* pp = p;

	cout << "sizeof(Primitives) = " << sizeof(Primitives) << endl;
	cout << "pp = " << (long)pp << endl;
	pp++;
	cout << "pp = " << (long)pp << endl;

	return 0;
}