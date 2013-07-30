// C03: global.cpp
// demonstration of global variables
#include <iostream>
using namespace std;

int globe;
void func();

int main() 
{
	globe = 12;
	cout << globle << endl;
	func();	// modifies globe
	cout << globe << endl;
}