/* exercise 2: struct_func.cpp
 * Create a struct declaration with a single member function, then create a definition for that 
 * member function. Create an object of your new data type, and call the member function.
 */
#include <iostream>

using namespace std;

struct Func
{
	void hello();
};

void Func::hello()
{
	cout << "Hello, World! This is an object!" << endl;
}

int main()
{
	Func hi;

	cout << "Testing..." << endl;
	hi.hello();

	return 0;
}