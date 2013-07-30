// C03: charlist.cpp
// display all the ASCII characters, demonstrating 'for'
#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 128; i++) 
		cout << " Value: " << i << " || Character: " << char(i) << endl;

	return 0;
}