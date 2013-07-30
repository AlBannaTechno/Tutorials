/* exercise 3: guard.cpp
 * Change your solution to exercise 2 so the struct is declared in a properly "guarded" header file,
 * with the definition in one cpp file and your main() in another.
 */
#include <iostream>
#include "ex3-guard.h"

void Func::hello()
{
	std::cout << "Hello, world! This is an object!" << std::endl;
}