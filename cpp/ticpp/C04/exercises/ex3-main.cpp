/* exercise 3: main.cpp
 * Change your solution to exercise 2 so the struct is declared in a properly "guarded" header file,
 * with the definition in one cpp file and your main() in another.
 */
#include <iostream>
#include "ex3-guard.h"

using namespace std;

int main()
{
	Func hi;

	cout << "Testing..." << endl;
	hi.hello();

	return 0;
}