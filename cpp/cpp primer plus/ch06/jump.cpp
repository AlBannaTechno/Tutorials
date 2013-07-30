// jump.cpp -- using continue and break
#include <iostream>

const int AR_SIZE = 80;

int main() {
    using namespace std;

    char line[AR_SIZE];
    int spaces = 0;

    cout << "Enter a line of text:\n";
    cin.get(line, AR_SIZE);
    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period:\n";

    for (int i = 0; line[i] != '\0'; ++i) {
        cout << line[i];  // display character
        if (line[i] == '.')  // quit if it's a period
            break;
        if (line[i] != ' ')  // skip rest of loop
            continue;
        spaces++;
    }
    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";

    return 0;
}
