#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    using namespace std;

    ostringstream strbuf;
    string file_name;

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;

    cout << "Please enter a file name to use: ";
    cin >> file_name;

    cout << "An in-memory stream" << endl;
    strbuf << "luckynumber: " << lucky << endl
           << "pi: " << pi << endl
           << "e: " << e << endl;

    string strval = strbuf.str();
    cout << strval;

    ofstream outf;
    outf.open(file_name.c_str(), ios_base::in);
    outf << strval;
    outf.close();

    cout << "Read data from the file - watch for errors." << endl;
    string newstr;
    ifstream inf;

    inf.open(file_name.c_str(), ios_base::in);
    if (inf) {  /* make sure the file exists before attempting to read. */
        int lucky2;
        inf >> newstr >> lucky2;
        if (lucky != lucky2)
            cerr << "ERROR! wrong " << newstr << lucky2 << endl;
        else
            cout << newstr << " OK" << endl;

        float pi2;
        inf >> newstr >> pi2;
        if (pi2 != pi)
            cerr << "ERROR! Wrong " << newstr << pi2 << endl;
        else
            cout << newstr << " OK" << endl;

        double e2;
        inf >> newstr >> e2;
        if (e2 != e)
            cerr << "ERROR: Wrong " << newstr << e2 << endl;
        else
            cout << newstr << " OK" << endl;

        inf.close();
    }

    cout << "Read from file line-by-line" << endl;
    inf.open(file_name.c_str(), ios_base::in);
    if (inf) {
        while (not inf.eof()) {
            getline(inf, newstr);
            cout << newstr << endl;
        }

        inf.close();
    }

    return 0;
}
