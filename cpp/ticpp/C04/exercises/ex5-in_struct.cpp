/* exercise 5: in_struct.cpp
 * Repeat exercise 4 but move the functions so they are member functions of the struct, and test 
 * again.
 */
#include <iostream>

using namespace std;

struct MyStruct
{
	int num;
	void change_num(int);
	void display_num();
};

void MyStruct::change_num(int nnum)
{
	num = nnum;
}

void MyStruct::display_num()
{
	cout << "num = " << num << endl;
}

int main()
{
	MyStruct mine;

	cout << "Setting 25 to num..." << endl;
	mine.change_num(25);
	cout << "Displaying num..." << endl;
	mine.display_num();

	return 0;
}