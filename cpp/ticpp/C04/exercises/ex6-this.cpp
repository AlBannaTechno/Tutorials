/* exercise 6: this.cpp
 * Create a class that (redundantly) performs data member selection and member function call using
 * the this keyword (which refers to the address of the current object)
 */
#include <iostream>

using namespace std;

struct MyStruct
{
	int num;
	void change_num(int num)
	{
		this->num = num;
	}

	int get_num()
	{
		return this->num;
	}

	void display_num()
	{
		cout << "this->num = " << this->get_num() << endl;
	}
};

int main()
{
	MyStruct mine;

	cout << "Setting 1024 to num..." << endl;
	mine.change_num(1024);
	cout << "Displaying num..." << endl;
	mine.display_num();

	return 0;
}