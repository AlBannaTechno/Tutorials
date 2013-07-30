// C03: forward.cpp
// forward function & data declarations
#include <iostream>
using namespace std;

// this is not actually external, but the compiler must be told it exists somewhere:
extern int i;
extern void func();

int main()
{
	i = 0;
	func();

	return 0;
}

int i; // the data definition

void func()
{
	i++;
	cout << i << endl;
}