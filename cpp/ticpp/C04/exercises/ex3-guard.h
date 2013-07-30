/* exercise 3: guard.h
 * Change your solution to exercise 2 so the struct is declared in a properly "guarded" header file,
 * with the definition in one cpp file and your main() in another.
 */
#ifndef GUARD_H
#define GUARD_H

struct Func
{
	void hello();	
};

#endif