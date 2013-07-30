// C: floating as Binary
#include <cstdlib>
#include <iostream>

#include "printBinary.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Must provide a number" << endl;
		return 1;
	}

	double d = atof(argv[1]);
	unsigned char* cp = reinterpret_cast<unsigned char*>(&d);

	for (int i = sizeof(double)-1; i >= 0; i -= 2) {
		printBinary(cp[i-1]);
		printBinary(cp[i]);
	}

	cout << endl;
	return 0;
}