// C04: CLibTest.cpp
// Test the c-like library
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include "CLib.h"

using namespace std;

int main()
{
	// define variables at the beginning of the block, as in C:
	CStash intStash, stringStash;
	int i;
	char* cp;
	ifstream in;
	string line;
	const int bufsize = 80;

	// now remember to initialize the variables:
	initialize(&intStash, sizeof(int));
	for (i = 0; i < 100; i++)
		add(&intStash, &i);
	for (i = 0; i < count(&intStash); i++)
		cout << "fetch(&intStash, " << i << ") = " << *(int*)fetch(&intStash, i) << endl;
	
	// holds 80-character strings:
	initialize(&stringStash, sizeof(char)*bufsize);
	in.open("CLibTest.cpp");
	assert(in);

	while (getline(in, line))
		add(&stringStash, line.c_str());
	
	i = 0;
	while ((cp = (char*)fetch(&stringStash, i++)) != 0)
		cout << "fetch(&stringStash, " << i << ") = " << cp << endl;

	cleanup(&intStash);
	cleanup(&stringStash);

	return 0;
}