// exercise 3: map_words.cpp
// map user input to numbers 
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	string word;

	while (1) {
		int code;
		
		cin >> word;
		if (word == "exit" || word == "return")
			break;

		// map words:
		if (word == "a" || word == "an" || word == "the")
			code = 0;

		else if (word == "after" || word == "before" || word == "beside" || word == "by" ||
				 word == "for" || word == "from" || word == "in" || word == "into" ||
				 word == "of" || word == "to")
			code = 1;

		else if (word == "if" || word == "else")
			code = 2;
		
		else if (word == "who" || word == "what" || word == "when" || word == "where" || 
				 word == "why")
			code = 3;

		else
			code = 4;

		// print description
		switch (code) {
			case 0:
				puts("article");
				break;
			case 1:
				puts("preposition");
				break;
			case 2:
				puts("conditional");
				break;
			case 3:
				puts("interrogative");
				break;
			default:
				puts("unmapped word");
		}
	}

	return 0;
}