// C03: reinterpret_cast.cpp
#include <iostream>
using namespace std;

const int sz = 100;

struct X { int a[sz]; };

void print(X*);

int main()
{
	X x;

	print (&x);

	int* xp = reinterpret_cast<int*>(&x);

	for (int* i = xp; i < xp + sz; i++)
		*i = 0;

	// can't use xp as an X* at this point unless you cast it back:
	print(reinterpret_cast<X*>(xp));
	// in this example, you can also just use the original identifier:
	print(&x);

	return 0;
}

void print(X* x)
{
	for (int i = 0; i < sz; i++)
		cout << x->a[i] << ' ';
	cout << endl << "----------------------" << endl; 
}