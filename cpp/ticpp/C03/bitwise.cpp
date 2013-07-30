// C03: bitwise.cpp
// Demonstration of bit manipulation
#include <iostream>

#include "printBinary.h"

using namespace std;

// a macro to save typing:
#define PR(STR, EXPR) \
	cout << STR; printBinary(EXPR); cout << endl;

int main()
{
	unsigned int getval;
	unsigned char a, b;

	cout << "Enter a number between 0 and 255: ";
	cin >> getval; a = getval;
	PR("a in binary: ", a);

	cout << "Enter a number between 0 and 255: ";
	cin >> getval; b = getval;
	PR("b in binary: ", b);

	PR("a | b = ", a | b);
	PR("a & b = ", a & b);
	PR("a ^ b = ", a ^ b);
	PR("~a = ", ~a);
	PR("~b = ", ~b);

	// an interesting bit pattern:
	unsigned char c = 0x5A;
	PR("c in binary: ", c);
	a |= c;
	PR("a |= c; a = ", a);
	b &= c;
	PR("b &= c; b = ", b);
	b ^= a;
	PR("b ^= a; b = ", b);

	return 0;
}