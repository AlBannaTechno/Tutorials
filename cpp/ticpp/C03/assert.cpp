// C03: assert.cpp
// use of the assert() debugging macro
#include <cassert>
using namespace std;

int main()
{
	int i = 100;
	assert(i != 100);

	return 0;
}