#include <string>
#include <iostream>


int main()
{
    using namespace std;

    const int THISYEAR = 2012;
    string yourName;
    int birthYear;

    cout << "What is your name? " << flush;
    getline(cin, yourName); //cin >> yourName;

    cout << "What year were you born? ";
    cin >> birthYear;

    cout << "Your name is " << yourName << " and you are approximately " << (THISYEAR - birthYear)
         << " years old." << endl;

    return 0;
}
