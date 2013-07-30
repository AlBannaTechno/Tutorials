// C03: mathops.cpp
// Mathmatical Operators
#include <iostream>
using namespace std;

// a macro to display a string and a value
#define PRINT(STR, VAR) \
	cout << STR << " = " << VAR << endl

int main()
{
	int i, j, k;
	float u, v, w; // applies to doubles, too

	cout << "Enter an integer: ";
	cin >> j;
	cout << "Enter another integer: ";
	cin >> k;

	PRINT("j", j); PRINT("k", k);
	i = j + k; PRINT("j + k", i);
	i = j - k; PRINT("j - k", i);
	i = k / j; PRINT("k / j", i);
	i = k * j; PRINT("k * j", i);
	i = k % j; PRINT("k % j", i);
	// the following only works with integers:
	j %= k; PRINT("j %= k", j);

	cout << "Enter a floating-point number: ";
	cin >> v;
	cout << "Enter another floating-point number: ";
	cin >> w;

	PRINT("v", v); PRINT("w", w);
	u = v + w; PRINT("v + w", u);
	u = v - w; PRINT("v - w", u);
	u = v * w; PRINT("v * w", u);
	u = v / w; PRINT("v / w", u);

	// the following works for intos, chars and doubles:
	PRINT("u", u); PRINT("v", v);
	u += v; PRINT("u += v", u);
	u -= v; PRINT("u -= v", u);
	u *= v; PRINT("u *= v", u);
	u /= v; PRINT("u /= v", u);

	return 0;
}