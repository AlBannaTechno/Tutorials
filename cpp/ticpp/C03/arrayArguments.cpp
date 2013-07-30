// C03: arrayArguments.cpp
#include <iostream>
#include <string>
using namespace std;

void func1(int[], int);
void func2(int*, int);
void print(int[], string, int);

int main()
{
	int a[5], b[5];
	
	// probably garbage values:
	print(a, "a", 5);
	print(b, "b", 5);

	// initialize the arrays:
	func1(a, 5);
	func1(b, 5);
	print(a, "a", 5);
	print(b, "b", 5);

	// notice the arrays are always modified:
	func2(a, 5);
	func2(b, 5);
	print(a, "a", 5);
	print(b, "b", 5);

	return 0;
}

void func1(int a[], int size)
{
	for (int i = 0; i < size; i++)
		a[i] = i * i + i;
}

void func2(int* a, int size)
{
	for (int i = 0; i < size; i++)
		a[i] = i * i + i;
}

void print(int a[], string name, int size) 
{
	for (int i = 0; i < size; i++) 
		cout << name << "[" << i << "] = " << a[i] << endl;
}