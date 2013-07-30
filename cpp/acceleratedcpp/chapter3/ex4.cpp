#include <iostream>
#include <string>

using std::cin;		using std::cout;
using std::endl;	using std::string;

int main() {
	// ask user for a bunch of words 
	cout << "Please enter a bunch of words. Use Ctrl+D to finish" << endl;

	// get user input
	string word;
	string::size_type s = 0;
	string::size_type l = 0;

	while (cin >> word) {
		if (s == 0 || word.size() < s)
			s = word.size();
		if (word.size() > l)
			l = word.size();
	}

	// print results
	cout << "The shortest word was " << s << " letters, the longest was " << l << endl;

	return 0;
}