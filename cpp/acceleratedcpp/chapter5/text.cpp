#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() 
{
	cout << "Enter a string: ";
	string tmp;
	getline(cin, tmp);

	while (tmp.find(' ', 0) != string::npos) {
		tmp[tmp.find_first_of(' ', 0)] = '\n';
	}
	cout << tmp << endl;
	return 0;
}