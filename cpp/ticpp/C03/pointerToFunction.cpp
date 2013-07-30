// C03: pointerToFunction.cpp
// defining and using a pointer to a function
#include <iostream>
using namespace std;

void func()
{
	cout << "func() called..." << endl;
}

int main()
{
	void (*fp)();	// define a function pointer
	fp = func;		// initialize it
	(*fp)();		// dereferencing calls the function
	void (*fp2)() = func;	// define and initialize
	(*fp2)();

	return 0;
}