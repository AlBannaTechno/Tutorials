// strings.cpp -- storing strings in an array
#include <iostream>
#include <cstring>  // for the strlen() function

int main() {
    using namespace std;

    const int SIZE = 15;
    char name1[SIZE];  // empty array
    char name2[SIZE] = "C++owboy";  // initialize array

    cout << "Howdy! I'm " << name2 << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has " << strlen(name1)
         << " letters and it is stored\nin an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';  // set to null character
    cout << "Here are the first three characters of my name: " << name2 << endl;

    return 0;
}
