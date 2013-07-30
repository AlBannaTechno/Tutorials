// C03: dynamicDebugFlags.cpp
#include <iostream>
#include <string>

using namespace std;

// debug flags aren't necessarily global:
bool debug = false;

int main(int argc, char* argv[]) 
{
	for (int i = 0; i < argc; i++)
		if (string(argv[i]) == "--debug=on")
			debug = true;

	bool go = true;

	while (go) {
		if (debug) {
			// debugging code here
			cout << "Debugger is now on!" << endl;
		} else {
			cout << "Debugger is now off!" << endl;
		}

		cout << "Turn debugger [on/off/quit]: ";
		string reply;
		cin >> reply;

		if (reply == "on")
			debug = true;
		if (reply == "off")
			debug = false;
		if (reply == "quit")
			break;
	}

	return 0;
}