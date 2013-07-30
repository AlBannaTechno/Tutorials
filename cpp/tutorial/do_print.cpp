#include <iostream>

using namespace std;

void DoPrint();
void DoPrint2();

int main()
{
	cout << "Starting main()" << endl;
	DoPrint();
	cout << "Ending main()" << endl;
	return 0;
}

void DoPrint()
{
	cout << "Starting DoPrint()" << endl;
	DoPrint2();
	DoPrint2();
	cout << "Ending DoPrint2()" << endl;
}

void DoPrint2()
{
	cout << "In DoPrint2()" << endl;
}