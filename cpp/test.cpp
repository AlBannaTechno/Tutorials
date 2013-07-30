#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "Enter a number: ";
	int x = 0;
	cin >> x;

	if (0 < x < 10)
		cout << "Number is below 10" << endl;
	if (10 < x < 20)
		cout << "Number is below 20" << endl;
	if (20 < x < 50)
		cout << "Number is below 50" << endl;

	return 0;
}
