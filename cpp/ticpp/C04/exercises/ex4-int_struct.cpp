/* exercise 4: int_struct.cpp
 * Create a struct with a single int data member, and two global functions, each of which takes a 
 * pointer to that struct. The first function has a second int argument and sets the struct's int
 * to the argument value, the second displays the int from the struct. Test the functions.
 */
#include <iostream>

using namespace std;

typedef struct MyStruct
{
	int num;
} MStruct;

void change_num(MStruct* s, int nnum)
{
	s->num = nnum;
}

void display_num(MStruct* s)
{
	cout << "s->num = " << s->num << endl;
}

int main()
{
	MStruct mine;

	cout << "Setting 25 to num..." << endl;
	change_num(&mine, 25);
	cout << "Displaying num..." << endl;
	display_num(&mine);

	return 0;
}