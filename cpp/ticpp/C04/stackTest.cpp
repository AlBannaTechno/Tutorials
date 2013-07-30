// C04: stackTest.cpp
// test of nested lists
#include <fstream>
#include <iostream>
#include <string>
#include "stack.h"
#include "../require.h"

using namespace std;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	Stack textlines;
	string line;

	// read file and store lines in the Stack:
	while (getline(in, line))
		textlines.push(new string(line));

	// pop the lines from the stack and print them:
	string* s;
	while ((s = (string*)textlines.pop()) != 0) {
		cout << *s << endl;
		delete s;
	}

	textlines.cleanup();

	return 0;
}
