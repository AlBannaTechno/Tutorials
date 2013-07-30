// exercise 2: prime_numbers.cpp
// find prime numbers with 2 nested for loops and modulus operator
#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i <= 100; i++) {
		int res = 0;
		for (int j = 1; j <= 100; j++) {
			if (i % j == 0)
				res += 1;
		}

		if (res == 2)
			cout << i << " is a prime number!" << endl;
	}
	
	return 0;	
}